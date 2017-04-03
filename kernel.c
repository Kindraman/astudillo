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

  	char *vidptr = (char*)0xb8000;//donde está la memoria de video
	unsigned int i = 0;
	unsigned int j = 0;
	
	while(message[j] != '\0') {
		if(message[j]=='-')
		{
			//salto de linea 
		}
		if(message[j]='>')//Tab = 4 espacios vacios
		{
			vidptr[i] = ' ';
			vidptr[i+2] = ' ';
			vidptr[i+4] = ' ';
			vidptr[i+6] = ' ';
			j++;
			i= i+8;
		//creo que esta bien xD (a revisar y testear) ***
		}

		vidptr[i] = message[j];
		vidptr[i+1] = 0x07;
		++j;
		i = i + 2;
	}
}

void main( void )
{
	int[] 
    char *str = ">Tarea 1 Sistemas Operativos->>Integrantes:->>>Cristobal Caipillan->>>Manuel Martinez";
	clear();
	showstring(str);
 for(;;); /* Bucle para mantener el SO corriendo */
}