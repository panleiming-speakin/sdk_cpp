
# centos

sudo yum install libcurl-devel
sudo yum install openssl-devel

# ubuntu

sudo apt-get install libcurl4-openssl-dev
sudo apt-get install openssl
sudo apt-get install libssl-dev

# 编译说明


解压第三方libbson

```
$ cd 3rdparty/
$ tar -xzvf libbson-1.6.3.tar.gz

$ cd ../
$ cmake .

```
