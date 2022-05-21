#!/bin/bash

thisDir=$(pwd)
mainDir=$(realpath $thisDir/..)

# Build library
pushd $mainDir
make -j all
dwarfdump -l libexample.so >microwalk/libexample.so.dwarf
popd

# Generate MAP file for library
pushd $MAP_GENERATOR_PATH
dotnet MapFileGenerator.dll $mainDir/libexample.so $thisDir/libexample.map
popd

# Build targets
for target in $(find . -name "target-*.c" -print)
do
  targetName=$(basename -- ${target%.*})
  
  gcc main.c $targetName.c -g -fno-inline -fno-split-stack -L "$mainDir" -lexample -I "$mainDir/src" -o $targetName
  
  pushd $MAP_GENERATOR_PATH
  dotnet MapFileGenerator.dll $thisDir/$targetName $thisDir/$targetName.map
  popd
  
  dwarfdump -l $targetName >$targetName.dwarf
done
