# UNO DHT11 OLED 环境监测器

基于 Arduino Uno、DHT11、SSD1306 OLED 和蓝牙串口的温湿度监测项目。

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

## 测试程序

`Bluetooth_Test/` 目录包含：

- `Bluetooth_Test.ino`：基础蓝牙串口收发测试
- `UNO_DHT11_Bluetooth_OLED.ino`：温湿度 OLED 显示及 VOFA+ FireWater 输出测试
