
void clear()
{
  	char *vidptr = (char*)0xb8000; 	//donde está la memoria de video
	unsigned int i = 0;
	unsigned int j = 0;
	//clear all
	while(j < 80 * 25 * 2) {
		//espacio en blanco
		vidptr[j] = ' ';
		// byte de atributo: gris sobre negro
		vidptr[j+1] = 0x08;
		j = j + 2;
	}
}

void showstring(char* message)
{
	int tam_palabras[] ={133,64,53,65};
  	char *vidptr = (char*)0xb8000;//donde está la memoria de video
	unsigned int i = 0;
	unsigned int j = 0;
	int p;
	
	while(message[j] != '\0') {
		if(message[j]=='-')
		{
			
			for(p=0;p<(tam_palabras[0]+4);p++){
				vidptr[i]=' ';
				vidptr[i+1]=0x08;
				i+=2;
			}
			j++;
		}
		else if(message[j]=='/'){

			for(p=0;p<(tam_palabras[1]+8);p++){
				vidptr[i]=' ';
				vidptr[i+1]=0x08;
				i+=2;
			}
			j++;
		}
		else if(message[j]=='*'){

			for(p=0;p<(tam_palabras[2]+8);p++){
				vidptr[i]=' ';
				vidptr[i+1]=0x08;
				i+=2;
			}
			j++;
		}
		/*else if(message[j]='>')//Tab = 4 espacios vacios
		{
			vidptr[i] = ' ';
			vidptr[i+1] = 0x08;
			i+=2;

			vidptr[i] = ' ';
			vidptr[i+1] = 0x08;
			i+=2;

			vidptr[i] = ' ';
			vidptr[i+1] = 0x08;
			i+=2;

			vidptr[i] = ' ';
			vidptr[i+1] = 0x08;
			i+=2;

			j++;
		}*/

			vidptr[i] = message[j];
			vidptr[i+1] = 0x07;
			++j;
			i = i + 2;
		
	}
}

void main( void )
{
	//int n[] = {41,30,30,30}; 
    char *str = "Tarea 1 Sistemas Operativos-Integrantes:/Cristobal Caipillan*Manuel Martinez";
	clear();
	showstring(str);
 for(;;); /* Bucle para mantener el SO corriendo */
}
