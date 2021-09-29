//const char dbw_Esp8266_Cmd_Table1[][60] = {
//	"AT+RST\r",                                //Reset ESP8266
//	"AT+CWLAP\r",                              //Scan wifi nearby
//	"AT+CWJAP='VTR-AL00','nf895637396'\r",     //Connect to certain wifi(need to rewrite)
//	"AT+CWQAP\r",                              //Quit connnecting
//	"AT+CIPMODE=1\r",                          //Penetrate mode(for send data to service)
//	"AT+CIPSEND\r",                            //Send data to service
//	"+++\r",                                  //Quit penetrate mode
//	"AT+CIPSTART='TCP','47.95.238.162',6768\r" //To set TCP connection to service
//	"AT+CIPCLOSE\r",                           //Close TCP connect
//	"AT+CIPSTATUS\r",                          //Show status of connection
//	"AT+CWMODE?\r",                            //Show mode of working 
//	"AT+UART=9600,8,1,0,0\r"                   //Change bps
//};
static unsigned char ESP8266_Cmd_Buff[60] = {0};
const unsigned char dbw_Esp8266_Cmd_Table[200] = {"AT+RST\rAT+CWLAP\rAT+CWJAP=\"VTR-AL01\",\"nf895637396\"\rAT+CWQAP\rAT+CIPMODE=1\rAT+CIPSEND\r+++\rAT+CIPSTART=\"TCP\",\"47.95.238.16\",6768\rAT+CIPCLOSE\rAT+CIPSTATUS\rAT+CWMODE?\rAT+UART=9600,8,1,0,0\r" };
const unsigned char dbw_Cmd_Table_Offset[] = {0,7,16,50,59,72,83,87,126,138,151,162};
											      
const unsigned char dbw_Cmd_Id_table[] = {
	0xff,                        //AT cmd to esp8266(wifi)
	0xfe,                        //Hex cmd to cc2540(bluetooth)
};