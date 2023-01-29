/*
 * APP.c
 *
 *  Created on: Dec 25, 2022
 *      Author: a7medDawoud
 */
#include "APP.h"

//------------ this function take two u8 numbers and print them on the 7Segme at the same time-----
void APP_vPrintNumberSS(u8 loc_u8SegmaPrintNumber1, u8 loc_u8SegmaPrintNumber2){
	_7Segma_vInit();
	u16 loc_delay;
	for(loc_delay=0;loc_delay<100;loc_delay++){
		_7Segma_vPrintNumber1(loc_u8SegmaPrintNumber1);
		_delay_ms(1);
		_7Segma_vPrintNumber2(loc_u8SegmaPrintNumber2);
		_delay_ms(1);
	}
}
void APP_vPrintTwoDigitNumberSS(u8 loc_u8SegmaPrintNumber){
	APP_vPrintNumberSS(loc_u8SegmaPrintNumber/10, loc_u8SegmaPrintNumber%10);
}
//------------ this function take a f32 number and print it on the 7Segme-----
void APP_vPrintDecimalNumberSS(f32 loc_f32SegmaDecimalNumber){
	//------------ DECIMAL POINT PIN------
	DIO_vSetPinDirection(PortB, Pin3, Pin_OutPut);
	u16 Loc_u16SegmaNumber=(loc_f32SegmaDecimalNumber*10);
	_7Segma_vEnableDot();
	APP_vPrintNumberSS(Loc_u16SegmaNumber/10, Loc_u16SegmaNumber%10);
	_7Segma_vDisbleDot();
}
//--------------- this function is used to print from 00 to 99--------
void APP_vPrint0to99SS(){
	u8 Loc_Count,Loc_Count2;
	for(Loc_Count=0;Loc_Count<10;Loc_Count++){
		for(Loc_Count2=0;Loc_Count2<10;Loc_Count2++){
			APP_vPrintNumberSS(Loc_Count,Loc_Count2);
		}
	}
}
//--------------- this function is used to print 1 minute on the 7 segma--------
void APP_vPrint1MinuteSS(){
	u8 Loc_Count,loc_delay;
	for(Loc_Count=0;Loc_Count<=60;Loc_Count++){
		for(loc_delay=0;loc_delay<4;loc_delay++){
			APP_vPrintTwoDigitNumberSS(Loc_Count);
		}
	}
}
/*--------------- this function is used to count the
 * (number clicks on pushbutton 1 Subtracted from number clicks on pushbutton 2)
 * and print it on the 7Segma*/
void APP_vClickCounterPB(){
	u8 Loc_Count;
	for(Loc_Count=0;Loc_Count<100;){
		if(PushButton_u8Button1()){
			Loc_Count++;
			APP_vPrintTwoDigitNumberSS(Loc_Count);
			APP_vPrintTwoDigitNumberSS(Loc_Count);
		}
		else if(PushButton_u8Button2()&&Loc_Count!=0){
			Loc_Count--;
			APP_vPrintTwoDigitNumberSS(Loc_Count);
			APP_vPrintTwoDigitNumberSS(Loc_Count);
		}
		else{
			APP_vPrintTwoDigitNumberSS(Loc_Count);
		}
	}
}
/*---------this function is used to count 3 minutes every minute a led will turn on--------*/
void APP_v3Leds1MinuteEachSS(){
	APP_vPrint1MinuteSS();
	LedAndBuzzer_vLed0Open();
	APP_vPrint1MinuteSS();
	LedAndBuzzer_vLed1Open();
	APP_vPrint1MinuteSS();
	LedAndBuzzer_vLed2Open();
	_delay_ms(250);
	_delay_ms(250);
	LedAndBuzzer_vLed0Close();
	LedAndBuzzer_vLed1Close();
	LedAndBuzzer_vLed2Close();
}
/*------------ this function is used to turn all LEDs and buzzer 3 times
 * -------------- to show that Task is finished--------*/
void APP_vTaskFinsh(){
	LedAndBuzzer_vFlash(3);
}
//-----------------
void APP_vWriteStringManyTimesLCD(u8 *Loc_u8Array,u8 Loc_u8size){
	LCD_vInit();
	u8 i;
	for(i=0;i<=((16/Loc_u8size));i++){
		LCD_vGoTo(LineOne,((Loc_u8size-1)*i));
		LCD_vWriteString(Loc_u8Array);
		_delay_ms(250);
		LCD_vClear();
	}
	for(i=0;i<=((16/Loc_u8size));i++){
		LCD_vGoTo(LineTwo,((Loc_u8size-1)*i));
		LCD_vWriteString(Loc_u8Array);
		_delay_ms(250);
		LCD_vClear();
	}
}
//-----------------
void APP_vToString(u8 str[], u16 num){
	u8 i, len = 0 ;
	u16 n,rem;
	n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	for (i = 0; i < len; i++)
	{
		rem = num % 10;
		num = num / 10;
		str[len - (i + 1)] = rem + '0';
	}
	str[len] = '\0';
}
//-----------------
void APP_vCalculatorLCD(){
	//-- while(!=)
	u8 Loc_u8Num1=0,Loc_u8Num2,Loc_u8Symbol1,Loc_u8Symbol2,Loc_u8sum;
	KAYPAD_vInit();
//Busy Wait
	while(1){
		Loc_u8Num1=KAYPAD_u8GetKey();
		_delay_ms(50);
		if(Loc_u8Num1!=0xff){
			LCD_vInit();
			LCD_vWriteCharacter(Loc_u8Num1+48);
			break;
		}
	}
	_delay_ms(50);
	KAYPAD_vInit();
	//--- delete all while 1 and replace it with if that take v and it count
	while(1){
		Loc_u8Symbol1=KAYPAD_u8GetKey();
		_delay_ms(50);
		if(Loc_u8Symbol1=='/'||Loc_u8Symbol1=='*'||Loc_u8Symbol1=='-'||Loc_u8Symbol1=='+'||Loc_u8Symbol1=='%'){
			LCD_vInitWithOutClear();
			LCD_vGoTo(LineOne,1);
			LCD_vWriteCharacter(Loc_u8Symbol1);
			break;
		}
	}
	_delay_ms(50);
	KAYPAD_vInit();
	while(1){
		Loc_u8Num2=KAYPAD_u8GetKey();
		_delay_ms(50);
		if(Loc_u8Num2!=0xff){
			LCD_vInitWithOutClear();
			LCD_vGoTo(LineOne,2);
			LCD_vWriteCharacter(Loc_u8Num2+48);
			break;
		}
	}
	_delay_ms(50);
	KAYPAD_vInit();
	while(1){
		Loc_u8Symbol2=KAYPAD_u8GetKey();
		_delay_ms(50);
		if(Loc_u8Symbol2=='='){
			LCD_vInitWithOutClear();
			LCD_vGoTo(LineOne,3);
			LCD_vWriteCharacter(Loc_u8Symbol2);
			break;
		}
	}
	if(Loc_u8Symbol1=='+'){
		Loc_u8sum=Loc_u8Num1+Loc_u8Num2;
	}
	else if(Loc_u8Symbol1=='-'){
		Loc_u8sum=Loc_u8Num1-Loc_u8Num2;
	}
	else if(Loc_u8Symbol1=='/'){
		Loc_u8sum=Loc_u8Num1/Loc_u8Num2;
	}
	else if(Loc_u8Symbol1=='*'){
		Loc_u8sum=Loc_u8Num1*Loc_u8Num2;
	}
	else if(Loc_u8Symbol1=='%'){
		Loc_u8sum=Loc_u8Num1%Loc_u8Num2;
	}
	else{
		//do nothing
	}
	LCD_vInitWithOutClear();
	LCD_vGoTo(LineOne,4);
	u8 arr[3];
	APP_vToString(arr,Loc_u8sum);
	LCD_vWriteString(arr);
	_delay_ms(100);
}
//-----------------
void APP_vLocker(u8 *Loc_CorrectUserName4,u8 *Loc_CorrectPassword3){
	u8 i;
	u8 user[4],pass[3];
	while(1){
		LCD_vInit();
		u8 User[]="Enter UserNam";
		LCD_vWriteString(User);
		for(i=0;i<4;i++){
			KAYPAD_vInit();
			while(1){
				user[i]=KAYPAD_u8GetKey();
				_delay_ms(50);
				if(user[i]!=0xff){
					LCD_vInitWithOutClear();
					LCD_vGoTo(LineTwo,i);
					LCD_vWriteCharacter((user[i])+48);
					break;
				}
			}

		}
		if(APP_u8compareArray(Loc_CorrectUserName4,user,4)==0){
			u8 Wrong[]="Wrong UserNam";
			LCD_vInit();
			LCD_vWriteString(Wrong);
			_delay_ms(250);
		}
		else if(APP_u8compareArray(Loc_CorrectUserName4,user,4)==1){
			break;
		}
		else{
			//do nothing
		}
	}
	u8 WrongPassCounter ;
	for(WrongPassCounter=0;WrongPassCounter<3;WrongPassCounter++){
		LCD_vInit();
		u8 Pass[]="Enter Pass";
		LCD_vWriteString(Pass);
		LCD_vGoTo(LineTwo,0);
		for(i=0;i<3;i++){
			KAYPAD_vInit();
			while(1){
				pass[i]=KAYPAD_u8GetKey();
				_delay_ms(50);
				if(pass[i]!=0xff){
					LCD_vInitWithOutClear();
					LCD_vGoTo(LineTwo,i);
					LCD_vWriteCharacter('*');
					break;
				}
			}
		}
		if(APP_u8compareArray(Loc_CorrectPassword3,pass,3)==0){
			LCD_vInit();
			u8 Wrong[]="Wrong Pass";
			LCD_vWriteString(Wrong);
			_delay_ms(250);
		}
		else if(APP_u8compareArray(Loc_CorrectPassword3,pass,3)==1){
			LCD_vInit();
			u8 Welcome[]="Welcome";
			LCD_vWriteString(Welcome);
			_delay_ms(250);
			break;
		}
		else{
			//do nothing
		}
	}
	if(WrongPassCounter==3){
		LCD_vInit();
		u8 Wrong1[]="Try latter";
		LCD_vWriteString(Wrong1);
	}
	else{
		//do nothing
	}
}
//----------------
u8 APP_u8compareArray(u8 *ptr1,u8 *ptr2,u8 size){
	u8 i;
	for(i=0;i<size;i++){
		if(ptr1[i]!=ptr2[i])
			return 0;
	}
	return 1;
}
//------------------------
void APP_vVolumeLCD(){
	LCD_vInit();
	u16 z;
	u8 counter=0,i,y;
	u8 chrr[8]={0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
	u8 chr0[8]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
	LCD_vCustomCharacter(chrr,0);
	LCD_vCustomCharacter(chr0,1);
	ADC_vInit(Polling,ADC1,FreeRunningMode);
	while(1){
		z=ADC_vGetVal(FreeRunningMode);
		while(z>311){
			z=z-311;
			counter++;
		}
		for(i=0;i<counter;i++){
			LCD_vWriteCharacter(0);
		}
		for(i=y;i>counter;i--){
			LCD_vGoTo(LineOne,i);
			LCD_vWriteCharacter(1);
		}
		y=counter;
		if(counter==16){
			LedAndBuzzer_vBuzzerOpen();
			_delay_ms(250);
			LedAndBuzzer_vBuzzerClose();
		}
		LCD_vGoTo(LineOne,0);
		counter=0;
	}
}
//-
void APP_vVolumeVerticalLCD(){
	LCD_vInit();
	ADC_vInit();
	s16 z;
	s8 counter=0,i,j,y=0;
	u8 arr1[8][8];
	for(i=0;i<8;i++){
		for(j=i;j<8;j++){
			arr1[i][7-j]=0x00;
		}
		for(j=0;j<=i;j++){
			arr1[i][7-j]=0x1F;
		}
		LCD_vCustomCharacter(arr1[i],i);
	}
	while(1){
		z=ADC_vGetVal();
		while(z>611){
			z=z-611;
			counter++;
		}
		for(i=y;i<counter;i++){
			LCD_vGoTo(LineOne,i);
			LCD_vWriteCharacter(i);
		}
		for(i=y;i>counter;i--){
			LCD_vGoTo(LineOne,i);
			LCD_vWriteCharacter(0);
		}
		y=counter;
		if(counter==8){
			LedAndBuzzer_vBuzzerOpen();
			_delay_ms(250);
			LedAndBuzzer_vBuzzerClose();
		}

		counter=0;
	}
}

