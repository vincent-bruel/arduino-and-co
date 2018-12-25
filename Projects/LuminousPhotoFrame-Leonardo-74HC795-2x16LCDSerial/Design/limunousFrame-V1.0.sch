EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino
LIBS:rur
LIBS:A6_GSM
LIBS:misc
LIBS:nodemcu
LIBS:sensors
LIBS:limunousFrame-V1.0-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "LuminousFrame"
Date ""
Rev "V1.0"
Comp "VIBI27"
Comment1 "A Frame to backlight a big photo with led spotlights"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L 74HC595 U1
U 1 1 58B36949
P 6100 2500
F 0 "U1" H 6250 3100 50  0000 C CNN
F 1 "74HC595" H 6100 1900 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 6100 2500 50  0001 C CNN
F 3 "" H 6100 2500 50  0000 C CNN
	1    6100 2500
	1    0    0    -1  
$EndComp
$Comp
L 74HC595 U2
U 1 1 58B36A2A
P 6100 4350
F 0 "U2" H 6250 4950 50  0000 C CNN
F 1 "74HC595" H 6100 3750 50  0000 C CNN
F 2 "Housings_DIP:DIP-16_W7.62mm" H 6100 4350 50  0001 C CNN
F 3 "" H 6100 4350 50  0000 C CNN
	1    6100 4350
	1    0    0    -1  
$EndComp
$Comp
L LED D9
U 1 1 58B36C51
P 8400 3800
F 0 "D9" H 8400 3900 50  0000 C CNN
F 1 "LED" H 8400 3700 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 3800 50  0001 C CNN
F 3 "" H 8400 3800 50  0000 C CNN
	1    8400 3800
	-1   0    0    1   
$EndComp
$Comp
L LED D10
U 1 1 58B36C82
P 8400 4100
F 0 "D10" H 8400 4200 50  0000 C CNN
F 1 "LED" H 8400 4000 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 4100 50  0001 C CNN
F 3 "" H 8400 4100 50  0000 C CNN
	1    8400 4100
	-1   0    0    1   
$EndComp
$Comp
L LED D15
U 1 1 58B36CB5
P 8400 5600
F 0 "D15" H 8400 5700 50  0000 C CNN
F 1 "LED" H 8400 5500 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 5600 50  0001 C CNN
F 3 "" H 8400 5600 50  0000 C CNN
	1    8400 5600
	-1   0    0    1   
$EndComp
$Comp
L LED D11
U 1 1 58B36CEA
P 8400 4400
F 0 "D11" H 8400 4500 50  0000 C CNN
F 1 "LED" H 8400 4300 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 4400 50  0001 C CNN
F 3 "" H 8400 4400 50  0000 C CNN
	1    8400 4400
	-1   0    0    1   
$EndComp
$Comp
L LED D12
U 1 1 58B36D21
P 8400 4700
F 0 "D12" H 8400 4800 50  0000 C CNN
F 1 "LED" H 8400 4600 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 4700 50  0001 C CNN
F 3 "" H 8400 4700 50  0000 C CNN
	1    8400 4700
	-1   0    0    1   
$EndComp
$Comp
L LED D16
U 1 1 58B36D5A
P 8400 5900
F 0 "D16" H 8400 6000 50  0000 C CNN
F 1 "LED" H 8400 5800 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 5900 50  0001 C CNN
F 3 "" H 8400 5900 50  0000 C CNN
	1    8400 5900
	-1   0    0    1   
$EndComp
$Comp
L LED D13
U 1 1 58B36D95
P 8400 5000
F 0 "D13" H 8400 5100 50  0000 C CNN
F 1 "LED" H 8400 4900 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 5000 50  0001 C CNN
F 3 "" H 8400 5000 50  0000 C CNN
	1    8400 5000
	-1   0    0    1   
$EndComp
$Comp
L LED D14
U 1 1 58B36DD4
P 8400 5300
F 0 "D14" H 8400 5400 50  0000 C CNN
F 1 "LED" H 8400 5200 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8400 5300 50  0001 C CNN
F 3 "" H 8400 5300 50  0000 C CNN
	1    8400 5300
	-1   0    0    1   
$EndComp
$Comp
L VCC #PWR01
U 1 1 58B371A5
P 2150 1400
F 0 "#PWR01" H 2150 1250 50  0001 C CNN
F 1 "VCC" H 2150 1550 50  0000 C CNN
F 2 "" H 2150 1400 50  0000 C CNN
F 3 "" H 2150 1400 50  0000 C CNN
	1    2150 1400
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR02
U 1 1 58B37348
P 2600 1400
F 0 "#PWR02" H 2600 1150 50  0001 C CNN
F 1 "GND" H 2600 1250 50  0000 C CNN
F 2 "" H 2600 1400 50  0000 C CNN
F 3 "" H 2600 1400 50  0000 C CNN
	1    2600 1400
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58B39DC2
P 8950 3800
F 0 "R9" V 9030 3800 50  0000 C CNN
F 1 "220" V 8950 3800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 3800 50  0001 C CNN
F 3 "" H 8950 3800 50  0000 C CNN
	1    8950 3800
	0    1    1    0   
$EndComp
$Comp
L R R10
U 1 1 58B39E29
P 8950 4100
F 0 "R10" V 9030 4100 50  0000 C CNN
F 1 "220" V 8950 4100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 4100 50  0001 C CNN
F 3 "" H 8950 4100 50  0000 C CNN
	1    8950 4100
	0    1    1    0   
$EndComp
$Comp
L R R11
U 1 1 58B39E80
P 8950 4400
F 0 "R11" V 9030 4400 50  0000 C CNN
F 1 "220" V 8950 4400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 4400 50  0001 C CNN
F 3 "" H 8950 4400 50  0000 C CNN
	1    8950 4400
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 58B39ED7
P 8950 4700
F 0 "R12" V 9030 4700 50  0000 C CNN
F 1 "220" V 8950 4700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 4700 50  0001 C CNN
F 3 "" H 8950 4700 50  0000 C CNN
	1    8950 4700
	0    1    1    0   
$EndComp
$Comp
L R R13
U 1 1 58B39F36
P 8950 5000
F 0 "R13" V 9030 5000 50  0000 C CNN
F 1 "220" V 8950 5000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 5000 50  0001 C CNN
F 3 "" H 8950 5000 50  0000 C CNN
	1    8950 5000
	0    1    1    0   
$EndComp
$Comp
L R R14
U 1 1 58B39F95
P 8950 5300
F 0 "R14" V 9030 5300 50  0000 C CNN
F 1 "220" V 8950 5300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 5300 50  0001 C CNN
F 3 "" H 8950 5300 50  0000 C CNN
	1    8950 5300
	0    1    1    0   
$EndComp
$Comp
L R R15
U 1 1 58B39FF8
P 8950 5600
F 0 "R15" V 9030 5600 50  0000 C CNN
F 1 "220" V 8950 5600 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 5600 50  0001 C CNN
F 3 "" H 8950 5600 50  0000 C CNN
	1    8950 5600
	0    1    1    0   
$EndComp
$Comp
L R R16
U 1 1 58B3A059
P 8950 5900
F 0 "R16" V 9030 5900 50  0000 C CNN
F 1 "220" V 8950 5900 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 5900 50  0001 C CNN
F 3 "" H 8950 5900 50  0000 C CNN
	1    8950 5900
	0    1    1    0   
$EndComp
Text Label 5200 2650 0    60   ~ 0
GND
Text Label 5150 4500 0    60   ~ 0
GND
$Comp
L PWR_FLAG #FLG03
U 1 1 58B3B19D
P 2150 1200
F 0 "#FLG03" H 2150 1295 50  0001 C CNN
F 1 "PWR_FLAG" H 2150 1380 50  0000 C CNN
F 2 "" H 2150 1200 50  0000 C CNN
F 3 "" H 2150 1200 50  0000 C CNN
	1    2150 1200
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG04
U 1 1 58B3B21A
P 2600 1200
F 0 "#FLG04" H 2600 1295 50  0001 C CNN
F 1 "PWR_FLAG" H 2600 1380 50  0000 C CNN
F 2 "" H 2600 1200 50  0000 C CNN
F 3 "" H 2600 1200 50  0000 C CNN
	1    2600 1200
	1    0    0    -1  
$EndComp
Text Notes 1900 900  0    60   ~ 0
Power section
Text Label 6900 2050 0    60   ~ 0
led1
Text Label 6900 2150 0    60   ~ 0
led2
Text Label 6900 2250 0    60   ~ 0
led3
Text Label 6900 2350 0    60   ~ 0
led4
Text Label 6900 2450 0    60   ~ 0
led5
Text Label 6900 2550 0    60   ~ 0
led6
Text Label 6900 2650 0    60   ~ 0
led7
Text Label 6900 2750 0    60   ~ 0
led8
Text Label 6900 3900 0    60   ~ 0
led9
Text Label 6900 4000 0    60   ~ 0
led10
Text Label 6900 4100 0    60   ~ 0
led11
Text Label 6900 4200 0    60   ~ 0
led12
Text Label 6900 4300 0    60   ~ 0
led13
Text Label 6900 4400 0    60   ~ 0
led14
Text Label 6900 4500 0    60   ~ 0
led15
Text Label 6900 4600 0    60   ~ 0
led16
Text Label 7950 1200 0    60   ~ 0
led8
Text Label 7950 1500 0    60   ~ 0
led7
Text Label 7950 1800 0    60   ~ 0
led6
Text Label 7950 2100 0    60   ~ 0
led5
Text Label 7950 2400 0    60   ~ 0
led4
Text Label 7950 2700 0    60   ~ 0
led3
Text Label 7950 3000 0    60   ~ 0
led2
Text Label 7950 3300 0    60   ~ 0
led1
Text Label 7950 3800 0    60   ~ 0
led16
Text Label 7950 4100 0    60   ~ 0
led15
Text Label 7950 4400 0    60   ~ 0
led14
Text Label 7950 4700 0    60   ~ 0
led13
Text Label 7950 5000 0    60   ~ 0
led12
Text Label 7950 5300 0    60   ~ 0
led11
Text Label 7950 5600 0    60   ~ 0
led10
Text Label 7950 5900 0    60   ~ 0
led9
Entry Wire Line
	7600 2050 7700 2150
Entry Wire Line
	7600 2150 7700 2250
Entry Wire Line
	7600 2250 7700 2350
Entry Wire Line
	7600 2350 7700 2450
Entry Wire Line
	7600 2450 7700 2550
Entry Wire Line
	7600 2550 7700 2650
Entry Wire Line
	7600 2650 7700 2750
Entry Wire Line
	7600 2750 7700 2850
Entry Wire Line
	7600 3900 7700 4000
Entry Wire Line
	7600 4000 7700 4100
Entry Wire Line
	7600 4100 7700 4200
Entry Wire Line
	7600 4200 7700 4300
Entry Wire Line
	7600 4300 7700 4400
Entry Wire Line
	7600 4400 7700 4500
Entry Wire Line
	7600 4500 7700 4600
Entry Wire Line
	7600 4600 7700 4700
Entry Wire Line
	7700 3700 7800 3800
Entry Wire Line
	7700 4000 7800 4100
Entry Wire Line
	7700 4300 7800 4400
Entry Wire Line
	7700 4600 7800 4700
Entry Wire Line
	7700 4900 7800 5000
Entry Wire Line
	7700 5200 7800 5300
Entry Wire Line
	7700 5500 7800 5600
Entry Wire Line
	7700 5800 7800 5900
Entry Wire Line
	7700 3200 7800 3300
Entry Wire Line
	7700 2900 7800 3000
Entry Wire Line
	7700 2600 7800 2700
Entry Wire Line
	7700 2300 7800 2400
Entry Wire Line
	7700 2000 7800 2100
Entry Wire Line
	7700 1700 7800 1800
Entry Wire Line
	7700 1400 7800 1500
Entry Wire Line
	7700 1100 7800 1200
$Comp
L GND #PWR05
U 1 1 58B4955D
P 9800 2250
F 0 "#PWR05" H 9800 2000 50  0001 C CNN
F 1 "GND" H 9800 2100 50  0000 C CNN
F 2 "" H 9800 2250 50  0000 C CNN
F 3 "" H 9800 2250 50  0000 C CNN
	1    9800 2250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 58B49CF6
P 9800 4800
F 0 "#PWR06" H 9800 4550 50  0001 C CNN
F 1 "GND" H 9800 4650 50  0000 C CNN
F 2 "" H 9800 4800 50  0000 C CNN
F 3 "" H 9800 4800 50  0000 C CNN
	1    9800 4800
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58B4A5DC
P 8950 1200
F 0 "R1" V 9030 1200 50  0000 C CNN
F 1 "220" V 8950 1200 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 1200 50  0001 C CNN
F 3 "" H 8950 1200 50  0000 C CNN
	1    8950 1200
	0    1    1    0   
$EndComp
$Comp
L LED D1
U 1 1 58B4A6AB
P 8550 1200
F 0 "D1" H 8550 1300 50  0000 C CNN
F 1 "LED" H 8550 1100 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 1200 50  0001 C CNN
F 3 "" H 8550 1200 50  0000 C CNN
	1    8550 1200
	-1   0    0    1   
$EndComp
$Comp
L R R2
U 1 1 58B4AA24
P 8950 1500
F 0 "R2" V 9030 1500 50  0000 C CNN
F 1 "220" V 8950 1500 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 1500 50  0001 C CNN
F 3 "" H 8950 1500 50  0000 C CNN
	1    8950 1500
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 58B4AA87
P 8950 1800
F 0 "R3" V 9030 1800 50  0000 C CNN
F 1 "220" V 8950 1800 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 1800 50  0001 C CNN
F 3 "" H 8950 1800 50  0000 C CNN
	1    8950 1800
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 58B4AACA
P 8950 2100
F 0 "R4" V 9030 2100 50  0000 C CNN
F 1 "220" V 8950 2100 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 2100 50  0001 C CNN
F 3 "" H 8950 2100 50  0000 C CNN
	1    8950 2100
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 58B4AB15
P 8950 2400
F 0 "R5" V 9030 2400 50  0000 C CNN
F 1 "220" V 8950 2400 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 2400 50  0001 C CNN
F 3 "" H 8950 2400 50  0000 C CNN
	1    8950 2400
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 58B4AB5A
P 8950 2700
F 0 "R6" V 9030 2700 50  0000 C CNN
F 1 "220" V 8950 2700 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 2700 50  0001 C CNN
F 3 "" H 8950 2700 50  0000 C CNN
	1    8950 2700
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 58B4ABA9
P 8950 3000
F 0 "R7" V 9030 3000 50  0000 C CNN
F 1 "220" V 8950 3000 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 3000 50  0001 C CNN
F 3 "" H 8950 3000 50  0000 C CNN
	1    8950 3000
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 58B4ABFC
P 8950 3300
F 0 "R8" V 9030 3300 50  0000 C CNN
F 1 "220" V 8950 3300 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_Power_L20.0mm_W6.4mm_P5.08mm_Vertical" V 8880 3300 50  0001 C CNN
F 3 "" H 8950 3300 50  0000 C CNN
	1    8950 3300
	0    1    1    0   
$EndComp
$Comp
L LED D2
U 1 1 58B4ADDB
P 8550 1500
F 0 "D2" H 8550 1600 50  0000 C CNN
F 1 "LED" H 8550 1400 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 1500 50  0001 C CNN
F 3 "" H 8550 1500 50  0000 C CNN
	1    8550 1500
	-1   0    0    1   
$EndComp
$Comp
L LED D3
U 1 1 58B4AE60
P 8550 1800
F 0 "D3" H 8550 1900 50  0000 C CNN
F 1 "LED" H 8550 1700 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 1800 50  0001 C CNN
F 3 "" H 8550 1800 50  0000 C CNN
	1    8550 1800
	-1   0    0    1   
$EndComp
$Comp
L LED D4
U 1 1 58B4AEB9
P 8550 2100
F 0 "D4" H 8550 2200 50  0000 C CNN
F 1 "LED" H 8550 2000 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 2100 50  0001 C CNN
F 3 "" H 8550 2100 50  0000 C CNN
	1    8550 2100
	-1   0    0    1   
$EndComp
$Comp
L LED D5
U 1 1 58B4AF1C
P 8550 2400
F 0 "D5" H 8550 2500 50  0000 C CNN
F 1 "LED" H 8550 2300 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 2400 50  0001 C CNN
F 3 "" H 8550 2400 50  0000 C CNN
	1    8550 2400
	-1   0    0    1   
$EndComp
$Comp
L LED D6
U 1 1 58B4AF79
P 8550 2700
F 0 "D6" H 8550 2800 50  0000 C CNN
F 1 "LED" H 8550 2600 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 2700 50  0001 C CNN
F 3 "" H 8550 2700 50  0000 C CNN
	1    8550 2700
	-1   0    0    1   
$EndComp
$Comp
L LED D7
U 1 1 58B4AFD8
P 8550 3000
F 0 "D7" H 8550 3100 50  0000 C CNN
F 1 "LED" H 8550 2900 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 3000 50  0001 C CNN
F 3 "" H 8550 3000 50  0000 C CNN
	1    8550 3000
	-1   0    0    1   
$EndComp
$Comp
L LED D8
U 1 1 58B4B03D
P 8550 3300
F 0 "D8" H 8550 3400 50  0000 C CNN
F 1 "LED" H 8550 3200 50  0000 C CNN
F 2 "Diodes_THT:D_5W_P5.08mm_Vertical_AnodeUp" H 8550 3300 50  0001 C CNN
F 3 "" H 8550 3300 50  0000 C CNN
	1    8550 3300
	-1   0    0    1   
$EndComp
Text Label 4800 2550 0    60   ~ 0
latch
Text Label 4800 2250 0    60   ~ 0
clock
Text Label 4800 2050 0    60   ~ 0
data
NoConn ~ 6800 4800
Text Label 5300 2350 0    60   ~ 0
VCC
Text Label 5300 4200 0    60   ~ 0
VCC
Wire Wire Line
	8550 3800 8800 3800
Wire Wire Line
	8550 4100 8800 4100
Wire Wire Line
	8550 4400 8800 4400
Wire Wire Line
	8550 4700 8800 4700
Wire Wire Line
	8550 5000 8800 5000
Wire Wire Line
	8550 5300 8800 5300
Wire Wire Line
	8550 5600 8800 5600
Wire Wire Line
	8550 5900 8800 5900
Wire Wire Line
	2600 1200 2600 1400
Wire Wire Line
	2150 1200 2150 1400
Wire Notes Line
	1800 800  1800 1700
Wire Notes Line
	1800 1700 2900 1700
Wire Notes Line
	2900 1700 2900 800 
Wire Notes Line
	2900 800  1800 800 
Wire Wire Line
	9100 1200 9600 1200
Wire Wire Line
	9600 1200 9600 1500
Wire Wire Line
	9600 1500 9600 1800
Wire Wire Line
	9600 1800 9600 2100
Wire Wire Line
	9600 2100 9600 2250
Wire Wire Line
	9600 2250 9600 2400
Wire Wire Line
	9600 2400 9600 2700
Wire Wire Line
	9600 2700 9600 3000
Wire Wire Line
	9600 3000 9600 3300
Wire Wire Line
	9100 1500 9600 1500
Connection ~ 9600 1500
Wire Wire Line
	9100 1800 9600 1800
Connection ~ 9600 1800
Wire Wire Line
	9100 2100 9600 2100
Connection ~ 9600 2100
Wire Wire Line
	9600 3300 9100 3300
Connection ~ 9600 2250
Wire Wire Line
	9100 2400 9600 2400
Connection ~ 9600 2400
Wire Wire Line
	9100 2700 9600 2700
Connection ~ 9600 2700
Wire Wire Line
	9100 3000 9600 3000
Connection ~ 9600 3000
Wire Wire Line
	9100 3800 9600 3800
Wire Wire Line
	9600 3800 9600 4100
Wire Wire Line
	9600 4100 9600 4400
Wire Wire Line
	9600 4400 9600 4700
Wire Wire Line
	9600 4700 9600 4800
Wire Wire Line
	9600 4800 9600 5000
Wire Wire Line
	9600 5000 9600 5300
Wire Wire Line
	9600 5300 9600 5600
Wire Wire Line
	9600 5600 9600 5900
Wire Wire Line
	9100 4100 9600 4100
Connection ~ 9600 4100
Wire Wire Line
	9100 4400 9600 4400
Connection ~ 9600 4400
Wire Wire Line
	9100 4700 9600 4700
Connection ~ 9600 4700
Wire Wire Line
	9600 5900 9100 5900
Connection ~ 9600 4800
Wire Wire Line
	9100 5600 9600 5600
Connection ~ 9600 5600
Wire Wire Line
	9100 5300 9600 5300
Connection ~ 9600 5300
Wire Wire Line
	9100 5000 9600 5000
Connection ~ 9600 5000
Wire Wire Line
	6800 2050 7600 2050
Wire Wire Line
	6800 2150 7600 2150
Wire Wire Line
	6800 2250 7600 2250
Wire Wire Line
	6800 2350 7600 2350
Wire Wire Line
	6800 2450 7600 2450
Wire Wire Line
	6800 2550 7600 2550
Wire Wire Line
	6800 2650 7600 2650
Wire Wire Line
	6800 2750 7600 2750
Wire Wire Line
	6800 3900 7600 3900
Wire Wire Line
	6800 4000 7600 4000
Wire Wire Line
	6800 4100 7600 4100
Wire Wire Line
	6800 4200 7600 4200
Wire Wire Line
	6800 4300 7600 4300
Wire Wire Line
	6800 4400 7600 4400
Wire Wire Line
	6800 4500 7600 4500
Wire Wire Line
	6800 4600 7600 4600
Wire Wire Line
	5400 4500 5150 4500
Wire Wire Line
	5400 2650 5200 2650
Wire Wire Line
	7800 1200 8400 1200
Wire Wire Line
	7800 1500 8400 1500
Wire Wire Line
	7800 1800 8400 1800
Wire Wire Line
	7800 2100 8400 2100
Wire Wire Line
	7800 2400 8400 2400
Wire Wire Line
	7800 2700 8400 2700
Wire Wire Line
	7800 3000 8400 3000
Wire Wire Line
	7800 3300 8400 3300
Wire Wire Line
	7800 3800 8250 3800
Wire Wire Line
	7800 4100 8250 4100
Wire Wire Line
	7800 4400 8250 4400
Wire Wire Line
	7800 4700 8250 4700
Wire Wire Line
	7800 5000 8250 5000
Wire Wire Line
	7800 5300 8250 5300
Wire Wire Line
	7800 5600 8250 5600
Wire Wire Line
	7800 5900 8250 5900
Wire Bus Line
	7700 1000 7700 1100
Wire Bus Line
	7700 1100 7700 1400
Wire Bus Line
	7700 1400 7700 1700
Wire Bus Line
	7700 1700 7700 2000
Wire Bus Line
	7700 2000 7700 2150
Wire Bus Line
	7700 2150 7700 2250
Wire Bus Line
	7700 2250 7700 2300
Wire Bus Line
	7700 2300 7700 2350
Wire Bus Line
	7700 2350 7700 2450
Wire Bus Line
	7700 2450 7700 2550
Wire Bus Line
	7700 2550 7700 2600
Wire Bus Line
	7700 2600 7700 2650
Wire Bus Line
	7700 2650 7700 2750
Wire Bus Line
	7700 2750 7700 2850
Wire Bus Line
	7700 2850 7700 2900
Wire Bus Line
	7700 2900 7700 3200
Wire Bus Line
	7700 3200 7700 3300
Wire Bus Line
	7700 3700 7700 4000
Wire Bus Line
	7700 4000 7700 4100
Wire Bus Line
	7700 4100 7700 4200
Wire Bus Line
	7700 4200 7700 4300
Wire Bus Line
	7700 4300 7700 4400
Wire Bus Line
	7700 4400 7700 4500
Wire Bus Line
	7700 4500 7700 4600
Wire Bus Line
	7700 4600 7700 4700
Wire Bus Line
	7700 4700 7700 4900
Wire Bus Line
	7700 4900 7700 5200
Wire Bus Line
	7700 5200 7700 5500
Wire Bus Line
	7700 5500 7700 5800
Wire Bus Line
	7700 5800 7700 5900
Wire Wire Line
	9800 2250 9600 2250
Wire Wire Line
	9800 4800 9600 4800
Wire Wire Line
	8800 1200 8700 1200
Wire Wire Line
	8700 2100 8800 2100
Wire Wire Line
	8700 1800 8800 1800
Wire Wire Line
	8700 1500 8800 1500
Wire Wire Line
	8700 2400 8800 2400
Wire Wire Line
	8700 2700 8800 2700
Wire Wire Line
	8700 3000 8800 3000
Wire Wire Line
	8700 3300 8800 3300
Wire Wire Line
	5350 3900 5400 3900
Wire Wire Line
	4800 2250 5150 2250
Wire Wire Line
	5150 2250 5400 2250
Wire Wire Line
	5150 2250 5150 4100
Wire Wire Line
	5150 4100 5400 4100
Wire Wire Line
	4100 2550 5050 2550
Wire Wire Line
	5050 2550 5400 2550
Wire Wire Line
	5050 2550 5050 4400
Wire Wire Line
	5050 4400 5400 4400
Wire Wire Line
	3650 2050 5400 2050
Wire Wire Line
	6800 2950 6800 3350
Wire Wire Line
	6800 3350 5350 3350
Wire Wire Line
	5350 3350 5350 3900
Wire Wire Line
	5400 2350 5300 2350
Wire Wire Line
	5400 4200 5300 4200
Connection ~ 5050 2550
Connection ~ 5150 2250
Wire Wire Line
	3650 2150 4800 2150
Wire Wire Line
	4800 2150 4800 2250
Wire Wire Line
	4100 2250 4100 2550
$Comp
L CONN_01X05 P1
U 1 1 58B55A76
P 3450 2250
F 0 "P1" H 3450 2550 50  0000 C CNN
F 1 "CONN_01X05" V 3550 2250 50  0000 C CNN
F 2 "Connectors:bornier5" H 3450 2250 50  0001 C CNN
F 3 "" H 3450 2250 50  0000 C CNN
	1    3450 2250
	-1   0    0    1   
$EndComp
Wire Wire Line
	3650 2250 4100 2250
Wire Wire Line
	3650 2350 3800 2350
Wire Wire Line
	3650 2450 3800 2450
Text Label 3800 2350 0    60   ~ 0
VCC
Text Label 3800 2450 0    60   ~ 0
GND
$EndSCHEMATC
