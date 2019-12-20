
#ifndef DECODE_FRAME_HPP
#define DECODE_FRAME_HPP
/*
编写者：lisn3188
网址：www.chiplab7.com
作者E-mail：lisn3188@163.com
编译环境：MDK-Lite  Version: 4.23
初版时间: 2012-05-25
测试： 本程序已在第七实验室的mini IMU上完成测试
功能：
使用串行中断程序接收mini IMU 的数据。
移植者需在自己编写对应的串口初始化程序，并开启接收中断。
在中断子程序中 需要做相应的改动

为了使用这个程序，你需要：
1.初始化你的串口，将波特率与模块的波特率设置成一致的
2.开启串口的接收中断，并参考以下程序编写中断子程序
  参考 void USART2_IRQHandler(void)
3.在主程序的循环体中，定时调用子程序：
  void UART2_CommandRoute(void)
  以检查是否收到新的数据帧
  所有的姿态数据和ADC值都会在 UART2_CommandRoute
  中进行更新。
4.使用 以下值会自动更新：

float 	yaw,  //偏航角
		pitch,//俯仰
		roll, //滚转
		alt,  //高度
		tempr,//温度
		press;//气压
int16_t ax, ay, az;//加速度计
int16_t gx, gy, gz;//陀螺仪
int16_t hx, hy, hz;//磁力计
------------------------------------
*/
#include <stdint.h> //int8_t int16_t int32_t 这些数据类型未定义，需要加入#include <stdint.h>
void Decode_frame(unsigned char data);

extern float 	yaw,  //偏航角
				pitch,//俯仰
				roll, //滚转
				alt,  //高度
				tempr,//温度
				press;//气压
//ADC值
extern int16_t ax, ay, az;//加速度计
extern int16_t gx, gy, gz;//陀螺仪
extern int16_t hx, hy, hz;//磁力计
//GPS位置信息
extern float GPS_Altitude , //天线离海平面的高度，-9999.9到9999.9米
			 Latitude_GPS , //纬度	 单位为度
			 Longitude_GPS , //经度  单位为度
			 Speed_GPS , //地面速率  单位  米每秒
			 Course_GPS ; //地面航向（000.0~359.9度，以真北为参考基准)
extern unsigned char GPS_STA_Num;

#endif