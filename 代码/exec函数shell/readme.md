# exec函数族实现shell会话（可执行cd命令）
  流程：  
  
  1.获取用户输入  
  2.利用`parse_command()`函数解析输入的命令，将其结果放入arg数组  
  3.然后判断arg数组第一个元素是否为cd，若是则在主进程执行`chdir()` 函数，进行工作区转换，否则执行`execute_command()` 函数执行命令。  
