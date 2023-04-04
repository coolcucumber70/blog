# git 学习
我这一次要彻底掌握vscode上的git指令,希望现在可以同步！
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
git branch dev //创建分支
git checkout master //切换分支
git branch -d dev  //删除分支
```
### 2.2查看分支
```cpp
git branch 列出本地已经存在的分支，并且当前分支会用*标记
git branch -r 查看远程版本库的分支列表
git branch -a 查看所有分支列表（包括本地和远程，remotes/开头的表示远程分支）
git branch -v 查看一个分支的最后一次提交
git branch --merged  查看哪些分支已经合并到当前分支
git branch --no-merged 查看所有未合并工作的分支
```
### 2.3远程库推拉
```
git pull origin 远程分支名称:本地分支名称 如果不写本地分支名称，则默认和远程分支同名 ，命令如下：
 git pull origin 远程分支名称
 推送到远程仓库：
 git push origin 分支名称
 假设我本地创建了一个名为dev的分支，远程仓库还没有这个分支，推送的命令是： 
 git push --set-upstream origin dev 这里注意一下 origin后面要习惯不写名字，保证上游分支与本地是同名的
 git branch -d 分支名称--删除分支，注意一点就是不能删除当前分支

```
### 2.4远程库关联
```cpp
git remote //查看远程的库的名称，远程库的名称
git remote -v//查看远程的库的地址，push和fetch
git remote add origin  url--远程库
git push -u origin master//第一次提交--其中master就是本地分支的名字，由于远程库是空的，我们第一次推送master分支时，加上了-u参数，Git不但会把本地的master分支内容推送的远程新的master分支，还会把本地的master分支和远程的master分支关联起来，在以后的推送或者拉取时就可以简化命令。
git remote rm origin    //此处的“删除”其实是解除了本地和远程的绑定关系，并不是物理上删除了远程库。远程库本身并没有任何改动。要真正删除远程库，需要登录到GitHub，在后台页面找到删除按钮再删除。
git push origin --delete 分支名//删除远程分支
```
### 2.5 合并分支
1、假如我们现在位于分支dev上，刚开发完自己负责的功能，执行了下列命令：
```cpp
git  add .
git  commit -m '某某功能已完成，提交到[分支名称]分支'
git  push -u origin 分支名称
```
2、首先切换到master分支上
git checkout master
3、如果是多人开发的话，需要把远程master分支上的代码pull下来
git pull origin master
4、然后把dev分支的代码合并到master上
git merge 分支名称
5、然后查看状态
git status
git push origin master

### 2.7高效解决分支 --分支管理策略
#### 2.7.1分支管理策略
git merge --no-ff -m "merge with no-ff" dev  //这个合并不是简单的改改指针，合并后分支还是在的
#### 2.7.2 修复bug的方法
软件开发中，bug就像家常便饭一样。有了bug就需要修复，在Git中，由于分支是如此的强大，所以，每个bug都可以通过一个新的临时分支来修复，修复后，合并分支，然后将临时分支删除。
当你接到一个修复一个代号101的bug的任务时，很自然地，你想创建一个分支issue-101来修复它，但是，等等，当前正在dev上进行的工作还没有提交：
```cpp
$ git status
On branch dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   hello.py

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)
	modified:   readme.txt

```

并不是你不想提交，而是工作只进行到一半，还没法提交，预计完成还需1天时间。但是，必须在两个小时内修复该bug，怎么办？
幸好，Git还提供了一个stash功能，可以把当前工作现场“储藏”起来，等以后恢复现场后继续工作：
```cpp
$ git stash
Saved working directory and index state WIP on dev: f52c633 add merge
现在，用git status查看工作区，就是干净的（除非有没有被Git管理的文件），因此可以放心地创建分支来修复bug。

首先确定要在哪个分支上修复bug，假定需要在master分支上修复，就从master创建临时分支：

$ git checkout master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 6 commits.
  (use "git push" to publish your local commits)

$ git checkout -b issue-101
Switched to a new branch 'issue-101'
现在修复bug，需要把“Git is free software ...”改为“Git is a free software ...”，然后提交：

$ git add readme.txt 
$ git commit -m "fix bug 101"
[issue-101 4c805e2] fix bug 101
 1 file changed, 1 insertion(+), 1 deletion(-)
修复完成后，切换到master分支，并完成合并，最后删除issue-101分支：

$ git switch master
Switched to branch 'master'
Your branch is ahead of 'origin/master' by 6 commits.
  (use "git push" to publish your local commits)

$ git merge --no-ff -m "merged bug fix 101" issue-101
Merge made by the 'recursive' strategy.
 readme.txt | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)
 ```

太棒了，原计划两个小时的bug修复只花了5分钟！现在，是时候接着回到dev分支干活了！

$ git switch dev
Switched to branch 'dev'

$ git status
On branch dev
nothing to commit, working tree clean
工作区是干净的，刚才的工作现场存到哪去了？用git stash list命令看看：

$ git stash list
stash@{0}: WIP on dev: f52c633 add merge
工作现场还在，Git把stash内容存在某个地方了，但是需要恢复一下，有两个办法：

一是用git stash apply恢复，但是恢复后，stash内容并不删除，你需要用git stash drop来删除；

另一种方式是用git stash pop，恢复的同时把stash内容也删了：

$ git stash pop
On branch dev
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

	new file:   hello.py

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   readme.txt

Dropped refs/stash@{0} (5d677e2ee266f39ea296182fb2354265b91b3b2a)
再用git stash list查看，就看不到任何stash内容了：

$ git stash list
你可以多次stash，恢复的时候，先用git stash list查看，然后恢复指定的stash，用命令：

$ git stash apply stash@{0}
#### 2.7.3多人协作的时候，如何保证其没有问题
测试我在dev上面的工作
