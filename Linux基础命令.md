# 1.ls 用于列出目录内容。
  ## 1.1语法  
    ls [选项] [文件或目录...]  
  ## 1.2参数  
    
    -1		每行只显示一个文件或目录。
    -l		长格式显示，显示详细信息（权限、所有者、大小、修改时间等）。  
    -a	--all	显示所有文件，包括以点 . 开头的隐藏文件。  
    -A	--almost-all	显示所有文件，但不包括 .（当前目录）和 ..（上级目录）。  
    -F	--classify	附加文件类型标识符 (/ 表示目录，* 表示可执行文件，@ 表示符号链接等）。 
    --color		彩色显示，通常默认开启。不同颜色代表不同的文件类型。  
    -r	--reverse	反向排序。
    -t		按修改时间排序，最新的在最前面。
    -S		按文件大小排序，最大的在最前面。
    -h	--human-readable	与 -l 一起使用，以人类易读的形式显示文件大小（如 K, M, G）。
    -R	--recursive	递归显示，列出所有子目录的内容。
    
 ## 1.3输出解析
    drwxr-xr-x  5 user  group   160B Oct 12 14:30  Documents
    -rw-r--r--  1 user  group   2.5K Oct 11 10:15  report.txt
    lrwxrwxrwx  1 user  group     11 Oct 10 09:20  link_to_report -> report.txt
    文件类型和权限 (drwxr-xr-x):
    第1位：文件类型
    
    -：普通文件
    
    d：目录
    
    l：符号链接
    
    b：块设备文件
    
    c：字符设备文件
    
    s：套接字文件
    
    p：管道文件
    
    第2-10位：权限，分三组（所有者/所属组/其他人），每组三位（读r/写w/执行x）。
    
    链接数 (5)：对于目录，通常表示其包含的子目录数（包括 . 和 ..）；对于文件，表示硬链接的数量。
    
    所有者 (user)：文件或目录的所有者。
    
    所属组 (group)：文件或目录的所属用户组。
    
    文件大小 (160B)：文件的大小。使用 -h 选项可以显示为 160B, 2.5K 等易读格式。
    
    最后修改时间 (Oct 12 14:30)：文件或目录的最后修改日期和时间。

名称 (Documents)：文件或目录的名称。如果是符号链接，会显示 指向的目标 -> 源文件。

 ## 1.4其他命令搭配使用
 ###   1.4.1通配符
      ls *.jpg          # 所有 jpg 文件
      ls project?.docx  # 如 project1.docx, projectA.docx
      ls [abc]*         # 以 a, b, 或 c 开头的所有文件
###    1.4.2管道
      ls -la | grep "report"
# 2.pwd 用于显示当前工作目录的完整路径
##  2.1语法
    pwd [选项]
##  2.2参数

    -L	--logical	显示逻辑路径（默认选项），解析符号链接
    -P	--physical	显示物理路径，不解析符号链接，显示实际路径
# 3.cd 切换当前工作目录的命令
 ## 3.1语法
    cd [选项] [目录]
 ## 3.2特殊符号
    命令	说明
    cd 或 cd ~	切换到当前用户的家目录
    cd -	切换到上一个工作目录
    cd ..	切换到上级目录
    cd ../..	切换到上两级目录
    cd .	停留在当前目录（通常用于脚本测试）
## 3.3高级用法
      # 切换到名称以 "Doc" 开头的目录
      cd Doc*
      
      # 切换到名称中包含 "project" 的目录
      cd *project*
##  3.4路径
###    3.4.1绝对路径
      cd /home/user/Documents  # 绝对路径
###    3.4.2相对路径
      cd Documents          # 相对路径
# 4.touch  创建空文件和更新文件时间戳的 Linux/Unix 命令。
 ## 4.1语法
    touch [选项] 文件...
 ## 4.2参数
    
    -a		只更改访问时间 (access time)
    -c	--no-create	不创建新文件，只更新时间戳
    -m		只更改修改时间 (modification time)
    -r	--reference=文件	使用指定参考文件的时间戳
    -t		使用指定的时间戳 (格式：[[CC]YY]MMDDhhmm[.ss])
    -d	--date=字符串	使用指定的日期字符串
# 5.mkdir 用于创建目录的命令
##  5.1语法
    mkdir [选项] 目录名...
##  5.2参数

    -p	--parents	递归创建所需的所有父目录
    -m	--mode	设置目录的权限模式（类似 chmod）
    -v	--verbose	显示详细信息，报告每个创建的目录
    -Z		设置 SELinux 安全上下文
##  5.3权限
    模式	数字	说明
    rwx------	700	仅所有者可读、写、执行
    rwxr-xr-x	755	所有者可读、写、执行，其他人只读和执行
    rwxrwx---	770	所有者和组可读、写、执行
    rwxr-x---	750	所有者可读、写、执行，组可读和执行
# 6.rmdir && rm 删除文件或目录的命令
##  6.1语法
    rm [选项] 文件或目录...
##  6.2参数

    -r	--recursive	递归删除目录及其内容
    -f	--force	强制删除，忽略不存在的文件，不提示确认
    -i	--interactive	交互模式，删除前逐一确认
    -v	--verbose	显示详细信息，报告每个删除的文件
    -d	--dir	删除空目录
    -I		在删除超过3个文件或递归删除前提示一次
# 7.cp  复制文件和目录的命令
##  7.1语法
    cp [选项] 源文件... 目标文件
    cp [选项] 源文件... 目标目录
##  7.2参数

    -r	--recursive	递归复制目录及其所有内容
    -i	--interactive	交互模式，覆盖前确认
    -f	--force	强制复制，覆盖已存在的目标文件
    -v	--verbose	显示详细信息，报告复制过程
    -p		保留文件属性（权限、时间戳等）
    -a	--archive	归档模式，相当于 -dR --preserve=all
    -u	--update	增量复制，只复制更新的文件
    -l	--link	创建硬链接而不是复制
    -s	--symbolic-link	创建符号链接而不是复制
    -b	--backup	创建备份覆盖的文件
    --preserve		保留指定的属性（默认：mode,ownership,timestamps）
# 8.mv  移动或重命名文件和目录的命令
##  8.1语法
    mv [选项] 源文件... 目标文件
    mv [选项] 源文件... 目标目录
##  8.2参数

    -i	--interactive	交互模式，覆盖前确认
    -f	--force	强制移动，覆盖已存在的目标文件
    -v	--verbose	显示详细信息，报告移动过程
    -n	--no-clobber	不覆盖已存在的文件
    -b	--backup	创建备份覆盖的文件
    -u	--update	增量移动，只移动更新的文件
    -t	--target-directory	指定目标目录
# 9.cat 连接文件并打印到标准输出的命令
##  9.1语法
    cat [选项] [文件]...
##  9.2参数

    -n	--number	显示行号
    -b	--number-nonblank	对非空行显示行号
    -s	--squeeze-blank	压缩连续空行为一行
    -E	--show-ends	在每行末尾显示 $
    -T	--show-tabs	将 TAB 显示为 ^I
    -A	--show-all	相当于 -vET
    -v	--show-nonprinting	显示非打印字符（除了换行和TAB）
##  9.3文件操作
    cat >> existing.txt                # 追加内容
  

