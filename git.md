# git 学习

## 一、git基础知识

### 1.1创建版本库

#### 1.1.1设置用户名与邮箱

下载git后，需要对用户名和邮箱进行赋值

git config --global user.name "Your Name"
git config --global user.email "email@example.com"

#### 1.1.2初始化git 

git init
git status //没有add进git的文件是红色的

git add readme.txt

git commit -m "add 3 files."

### 1.2版本穿梭

#### 1.2.1查看版本号

git log --pretty=oneline

git log --graph --pretty=oneline --abbrev-commit

git reset --hard HEAD^ //回溯到上一个版本
git reflog  //查看过去的版本号

## 二、git分支管理

### 2.1创建与切换分支


```cpp
git checkout -b dev
git switch -c dev//创建并切换分支

git checkout master //切换分支

git branch -d dev  //删除分支
git branch dev //创建分支
```
### 2.2合并分支
git merge --no-ff -m "merge with no-ff" dev  //这个合并不是简单的改改指针，合并后分支还是在的
git merge dev   //合并分支，在master的主支上来合并
### 2.3多人协作远程库
#### 2.3.1远程库
```cpp
git remote //查看远程的库的名称，远程库的名称
git remote -v//查看远程的库的地址，push和fetch
git remote add origin  url
git push -u origin master//第一次提交
git remote rm origin    //与远程连接地址终端
git push origin --delete 分支名//删除远程分支