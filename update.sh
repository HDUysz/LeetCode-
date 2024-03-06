#!/bin/bash

# 停止脚本在出现错误时继续执行
set -e

# 查看当前Git仓库状态
git status

# 添加所有更改到暂存区
git add *

# 提交更改
git commit -m "update"

# 从远程仓库拉取最新代码
git pull

# 将本地的master分支推送到远程仓库
# 如果出错，尝试推送到main分支
git push origin master || git push origin main

echo "更新完成"
