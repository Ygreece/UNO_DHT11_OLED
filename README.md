# UNO DHT11 OLED 环境监测器

> **课程设计项目**：智能传感网络与检测系统综合设计（67）

这是一个面向课程设计的简单智能传感监测系统，基于 Arduino Uno、DHT11、SSD1306 OLED 和蓝牙串口，实现环境温湿度采集、显示、报警与风扇控制。

项目当前以“能运行、易展示、便于后续整理报告”为目标，后续可在此基础上补充系统框图、流程图、实验数据和 Word 汇报材料。

## 功能

- OLED 显示温度和湿度
- 温度预警与严重报警
- 蜂鸣器和板载 LED 状态提示
- 风扇自动、强制开启和强制关闭模式
- 按键切换 OLED 页面
- 通过蓝牙串口查询状态和控制风扇
- 提供 VOFA+ FireWater 串口输出测试程序

## 硬件连接

| 模块 | Arduino Uno |
| --- | --- |
| DHT11 DATA | D2 |
| 蜂鸣器 | D3 |
| 页面按键 | D4（使用内部上拉） |
| 风扇控制 | D9 |
| OLED SDA | A4 |
| OLED SCL | A5 |
| OLED 地址 | `0x3C` |

蓝牙模块使用 Arduino Uno 的硬件串口，波特率为 `9600`。风扇驱动应使用合适的晶体管或继电器模块，不要直接由 Arduino 引脚带动大功率负载。

## 软件依赖

在 Arduino IDE 的库管理器中安装：

- Adafruit GFX Library
- Adafruit SSD1306
- DHT sensor library

## 使用方式

1. 在 Arduino IDE 中打开 `UNO_DHT11_OLED/UNO_DHT11_OLED.ino`。
2. 安装所需库并选择 Arduino Uno 开发板。
3. 按照上表完成接线。
4. 编译并上传程序。
5. 通过按键切换 OLED 页面，或通过蓝牙发送以下命令：

```text
STATUS
HELP
PAGE 0
PAGE 1
PAGE 2
FAN AUTO
FAN ON
FAN OFF
```

温度达到 `28 °C` 时进入预警，达到 `30 °C` 时进入严重报警；报警阈值回差为 `1 °C`。

## 项目结构

```text
UNO_DHT11_OLED/
├── UNO_DHT11_OLED.ino       # 主程序：采集、显示、报警、风扇和蓝牙控制
├── Bluetooth_Test/          # 蓝牙与传感器显示测试程序
│   ├── Bluetooth_Test.ino
│   └── UNO_DHT11_Bluetooth_OLED.ino
├── Bluetooth_Test_old.txt   # 早期测试记录
├── README.md                # 项目说明与复现步骤
└── docs/                    # 预留：课程设计报告、图片、流程图和实验记录
```

建议后续 Word 汇报按以下章节整理：

1. 设计任务与需求分析
2. 系统总体方案与系统框图
3. 硬件电路设计与元器件说明
4. 软件流程与程序模块设计
5. 蓝牙通信协议与人机交互
6. 系统调试、实验数据与结果分析
7. 总结与改进方向


- `Bluetooth_Test.ino`：基础蓝牙串口收发测试
- `UNO_DHT11_Bluetooth_OLED.ino`：温湿度 OLED 显示及 VOFA+ FireWater 输出测试
