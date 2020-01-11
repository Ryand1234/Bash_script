#!/bin/bash
cd ~/linux-5.4.10/
make savedefconfig
cp defconfig arch/amd64/configs/my_defconfig
export ARCH=amd64
make my_defconfig
