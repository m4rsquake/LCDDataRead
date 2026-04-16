# LCDDataRead

LCDDataRead 是一个基于 STC8A8K64D4 系列单片机的 Keil uVision 工程。

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
