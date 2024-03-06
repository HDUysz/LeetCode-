@echo off

REM 显示当前的 Git 仓库状态
git status

REM 添加所有修改的文件到暂存区
git add *

REM 提交更改，包含一个更新说明
git commit -m "update"

REM 拉取远程仓库的最新代码
git pull

REM 推送代码到远程的 master 分支
git push origin main

echo 更新完成!
