----------------------
# 弹弹方块C语言实现 #
----------------------
实现这个项目需要Linux系统的 VT控制码,即 VT100 ;
VT100 是一个终端类型定义,VT100控制码是用来在终端扩展显示的代码。
所有VT码都以 \033 开头，可以在命令行shell的echo中或者C语言的printf中输出VT100的控制字符。
具体格式有两种：
 *数字形式：		\033[<数字>m
 *控制字符形式：	\033[K
/详见VT100控制码表；
