# gtest-demo
This demo shows how to use gtest in your project and it was generated with Qt Creator 4.0.3(Based on Qt 5.6.1,GCC 4.9.1 20140922,Red Hat 4.9.1-10 64bit).

# Prepare environment of gtest
This demo was base on centos7. If you already have gtest on your machine, ignore this item.
## 1.更新dnf源
sudo yum install epel-release
sudo yum install dnf
## 2.安装gtest
sudo dnf install dnf-plugins-core
sudo dnf install gtest gtest-devel
## 3.检查是否安装成功
find /usr -name gtest.h
显示/usr/include/gtest/gtest.h即为安装成功.

# Examples
## 1.test public method
MyTest and MyGTest class show how to test public methods.
## 2.test private method
### 2.1 use macro definition
PrivateTest and PrivateMemberTest class show how to use macro definition to test private methods.   
### 2.2 use FRIEND_TEST
FriendTest and FriendMemberTest show how to use FRIEND_TEST to test private methods.    
### 2.3 use PIMPL
MyClass and MyClassTest show how to use PIMPL to test private methods. 