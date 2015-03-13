#include <ctime>
#include <string>
#include "huffman.h"

using namespace std;


/*
 =======================================================================================================================
    MAIN PRINCIPALE DEL PROGETTO
 =======================================================================================================================
 */

int main()
{
  /*====================*/
	char nome_file[50];   /* variabile che contiene il nome del file da comprimere, non utilizzo string
	                      * poiche' dopo non potrei usare le funzioni sui file */
	clock_t Inizio,Fine;  /* dichiaro due variabili per tener traccia dell inizio e della fine del programma */
	double time;   /* dichiaro una variabile che conterra' il tempo impiegato */
	char   scelta;   /*variabile per effettura la scelta nello switch case*/
/*====================*/
    cout << endl;
	cout << "=========================================================================" << endl;
	cout << "=======          Progetto di Algoritmi e Strutture Dati           =======" << endl;
	cout << "======             Compressione e Decompressione file:             ======" << endl;
	cout << "=====                    La codifica di Huffmann                    =====" << endl;
	cout << "====                di Anna Braccolino mat. 0124/248                 ====" << endl;
	cout << "=========================================================================" << endl;


	/*utilizzo un for infinito così anche dopo aver effettuato la scelta
	 sarà possibile scegliere ancora finchè non si esce*/
	cout <<"vuoi comprimere o decomprimere un file?"<<endl;
	for(;;)
    {
        cout << "=========================================" << endl;
        cout << "** 1. Comprimere" << endl;
        cout << "** 2. Decomprimere" << endl;
        cout << "** 3. Esci" << endl;
        cout << "** ---> ";
        cin >> scelta;
        cout << "=========================================" << endl;

/*la prima scelta riguarda la compressione del file*/
switch(scelta)
        {
        case '1':
		{
		cout << endl;
    cout << "\t==========================================================" << endl;
    cout << endl;
    cout << "\t==Compressione di un file tramite la codifica di Huffman==" << endl;
    cout << endl;
    cout << "\t==========================================================" << endl;
    cout << endl;

/*viene chiesto di inserire il file che si vuole comprimere compreso di estensione*/
	cout <<"Inserire il nome del file da comprimere (compreso di estensione)"<<endl;
	cout <<"--->";
	cin >> nome_file;
	Inizio = clock();/*faccio partire il tempo*/
	ifstream File_da_comprimere(nome_file); /* se il file non esiste stampo un errore a video */
	if(!File_da_comprimere) {
		cout << "il file non esiste!\n";
		system("pause");
		return -1;
	}
	Encoder encode;
	encode.Encode(nome_file,"Encoded_File.huf");/*richiamo il metodo Encode che si occupa di comprimere il file*/
	Valuta_Compressione v_comp(nome_file,"Encoded_File.huf");/*richiamo il metodo Valuta_Compressione che si occupa 
	                                                                                 di calcolare il tasso di compressione */

Fine = clock();/*fermo il tempo*/
time = ((double)(Fine-Inizio))/CLOCKS_PER_SEC; //calcola il tempo impiegato

/*Stampo in output i risultati della compressione stampando:
la dimensione in byte del file
tasso di compressione
guadagno di spazio dopo la compressione del file*/
cout << "\t==========================================================" << endl;
cout << "\t=====              Risultati Compressione            =====" << endl;
cout << "\t==========================================================" << endl;
cout << " Il file " << nome_file << " e' di " << v_comp.Calcola_Dimensione_File() << " byte" << endl;
cout << " Compression Rate: "<< v_comp.Compression_Rate() << endl;
cout << " Guadagno di spazio: "<< v_comp.Guadagno_Spazio() << " %" << endl << endl;
cout << " Il File e' stato codificato con il nome:Encoded_File.huf" << endl;
cout <<"----------------------------------------------------------"<<endl;
cout << " Eseguito in:  " << time << "sec" << endl;

}
/*la seconda scelta riguarda la decompressione del file*/
	break;
	case '2':
	{ cout << endl;
      cout << "\t============================================================" << endl;
      cout << endl;
      cout << "\t==Decompressione di un file tramite la codifica di Huffman==" << endl;
      cout << endl;
      cout << "\t============================================================" << endl;
      cout << endl;

	  /*viene chiesto di inserire il file da decomprimere*/
	cout <<"Inserire il nome del file da decomprimere (compreso di estensione)"<<endl;
	cout<<"---->";
	cin >> nome_file;
	Inizio = clock();/*faccio partire il tempo*/
	ifstream File_da_comprimere(nome_file); /* se il file non esiste stampo un errore a video */
	if(!File_da_comprimere) {
		cout << "il file non esiste!\n";
		system("pause");
		return -1;
	}
	Decoder decode;
	decode.Decode("Encoded_File.huf","Decrypted_File.dhuf");/*richiamo la funzione decode che decomprime il file*/
	Fine = clock();/*fermo il tempo*/

	time = ((double)(Fine-Inizio))/CLOCKS_PER_SEC; //calcola il tempo impiegato
    cout <<endl;
	cout << " Il file inserito e' stato decodificato con il nome: Decrypted_File.dhuf " << endl;
	cout <<"----------------------------------------------------------"<<endl;
	cout << " Eseguito in: " << time << "sec" << endl;
	}

	break;
	/*la tereza scelta implica la chiusura del programma*/
	case '3':
            exit(0);

			/*nel caso in cui viene inserito un carattere errato viene stampata la seguente riga*/
        default:
            cout << "Spiacente '" << scelta << "' non e' un carattere accettato, riprovare\n";
	}

	}

	system("pause");
    return 0;

}
