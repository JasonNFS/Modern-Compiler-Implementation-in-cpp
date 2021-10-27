#!/bin/bash
tiger=$1
file_dir=$2
echo "staring running regression test for ${tiger}"
if [[ ! -d ${file_dir} ]];then
  echo "${file_dir} not exist!"
  exit 1
fi

for Code in "${file_dir}"/*.tig; do
  [[ -e "$Code" ]] || continue
  echo "parsing $Code ..."
  ${tiger} "$Code"
  status=$?
  if [[ $status -eq 0 ]]; then
    echo "$Code compile successful"
  else
    echo "$Code compile failed!"
    exit 1
  fi
done
