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

git reset --hard HEAD^ //回溯到上一个版本
git reflog  //查看过去的版本号

## 二、git分支管理

创建分支并切换到分支：
git checkout -b dev
git switch -c dev
git checkout master 切换分支
git merge dev   --合并分支，在master的主支上来合并

git branch -d dev删除分支
