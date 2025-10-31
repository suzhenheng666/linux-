# 1.克隆仓库到本地
  git clone git@github.com:用户名/仓库名.git
# 2.创建新文件并提交
  #创建文件  
  echo "# 我的项目" > README.md  
  
  #添加到暂存区  
  git add README.md  
  
  #提交更改  
  git commit -m "添加README文件"  
  
  #推送到GitHub  
  git push origin main  
# 3.分支管理
  #查看分支  
  git branch  
  
  #切换分支  
  git checkout 分支名  
  
  #创建并切换分支  
  git checkout -b 新分支名  
  
  #合并分支  
  git merge 分支名  
  
  #删除分支  
  git branch -d 分支名  

