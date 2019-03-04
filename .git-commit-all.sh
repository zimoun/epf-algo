#!/bin/bash

filename=example

if [[ ! -d .git ]]
then
    echo "Init."
    git init
else
    echo "Big dance already done."
    echo "File modified:"
    git status -u -s
    echo "Automatic commit."
    git commit -am "automatic message"
    exit 0
fi

git add ${filename}.org
git commit -am "Org source"

#emacs ${filename}.org -f org-babel-execute-buffer

git add ${filename}.html
git commit -am "HTML page"

for i in $(seq 1 6)
do
    cp Supplementary/main-v${i}.c main.c
    git add main.c
    git commit -am "version $i"
done

git add Supplementary/*
git commit -am "add Supplementary materials"

git add .git-commit-all.sh
git commit -am "add Git repo generator script"
