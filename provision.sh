#! /usr/bin/env bash

# Some dependencies
#sudo apt-get update
#sudo apt-get install -y libjudy-dev make g++ gdb git

## cmd for centOS
 sudo yum install Judy.x86_64
(
#    cd /vagrant/
    git submodule update --init --recursive
)
