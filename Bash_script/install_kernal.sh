#!/bin/bash
if test $# -lt 1
then
	echo "Please provide your name"
	exit 1
fi
echo "Hello $1, Downloading will be started shortly"
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.4.10.tar.xz
echo "Kernel Downloading Compeleted\n Extracting started."
unxz -v linux-5.4.10.tar.xz
echo "Extraction Compeleted"
echo "PGP key Download starting..."
wget https://cdn.kernel.org/pub/linux/kernel/v5.x/linux-5.4.10.tar.sign
echo "PGP Key Download Compelete"
gpg --recv-keys 79BE3E4300411886
echo "Key Verification"
gpg --verify linux-5.4.10.tar.sign
echo "Final Extraction"
tar xvf linux-5.4.10.tar
echo "Kernel setup compeleted."
cd linux-5.4.10

