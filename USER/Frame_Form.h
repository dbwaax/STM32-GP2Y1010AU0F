#define header_Hardware 0x24
#define Tail_Hardware 0x23
struct Send_Hardware_Cmd
{
	char header;    //Header of Frame(0x24 $)
	char Cmd_Id;    //Ditinguish the cmd
	char Cmd[50];   //Commmand to hardware
	int Frame_Size; //Record the size of Frame;
	char Frame_tail;//End of Frame(0x23 #)
}SH1;

