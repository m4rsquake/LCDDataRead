# LCDDataRead

LCDDataRead 是一个基于 STC8A8K64D4 系列单片机的 Keil uVision 工程。

## 项目功能
本项目的目标是：

- 采集成品芯片数码管相关信号
- 对数码管显示信号进行解析/翻译
- 将这些段信号还原为实际数字结果

也就是说，这个项目不是直接驱动数码管显示，而是把现有芯片输出到数码管上的信号“读出来”，再转换成可处理的真实数字。

## 目录说明
当前目录中包含：
- `LCDDataRead.uvproj` / `LCDDataRead.uvopt`：Keil 工程文件
- `main.c`：主程序入口
- `ADC.c`, `timer.c`, `uart.c`, `PowerCheck.c` 等源文件
- `LIB/`：配套库与启动代码
- `Objects/`, `Listings/`：构建输出与列表文件

## 开发环境
- Keil uVision / C51
- 目标器件：STC8A8K64D4 Series
- 工程时钟配置（见 `.uvproj`）：35 MHz

## 说明
这是从本地 Windows 目录初始化并推送到 GitHub 的首个版本。
