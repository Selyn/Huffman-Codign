# Huffman-Coding
Sviluppo di un encoder (codificatore) ed un decoder (decodificatore) che utilizza la codifica di Huffman. Codifica qualunque file di testo (.txt) e anche altri tipi di formati (bmp, wav, ...)

Development of an encoder and a decoder that uses the Huffman coding. Encoding any text file (.txt) and also other types of formats (bmp, wav, ...)

Il progetto è stato implementato in C++ con l’ambiente di sviluppo CodeBlock versione12.11

Sono state implementate nove classi di oggetti:

#File_Data
Contieni gli attributi utilizzati da altre classi. Questa classe serve per rendere disponibili informazioni ricavate dall'analisi del file da comprimere. Al suo interno gli attributi sono stati dichiarati protected per essere disponibili alle altre classi.

#Node
Crea i due tipi di nodo che formano l’albero. Attraverso l’overloading delle funzioni sono stati implementati due costruttori, uno per il nodo interno e l’altro per il nodo foglia. Alcuni dei metodi al suo interno sono funzioni get per i dati membro della classe. È stato utilizzato un operator int(),cioè un operatore di cast che verrà utilizzato per trattare gli oggetti Node come int rispetto alle loro frequenze.

#Min_Heap
Simula una coda di Min-priority,i metodi utilizzati sono quelli di inserimento ed estrazione.

#Tree
È formata dalle altre tre classi,Node,Min_Heap e File_Data . Appena sono state raccolte le informazioni del file inserito viene chiamato il costruttore. Quando viene creato l'oggetto il costruttore di default genera l'albero iniziando da un array di nodi foglia e attraverso l'heap effettua gli inserimenti le estrazioni e le fusioni. I metodi get di Tree restituiscono le foglie che servono alla codifica e la radice che servirà alla decodifica.

#Read_File
Questa classe permette di leggere il file in input. Ci sono due modalità di lettura, per il file sorgente vi è una lettura byte per byte, per il file codificato una lettura bit per bit. Al suo interno è dichiarato il metodo Read_Source_File, che raccoglie le informazioni per la costruzione dell'albero.

#Write_File
Classe utilizzata per scrivere sul file. I metodi dichiarati servono per scrivere sul file codificato e decodificato.

#Encoder
Permette di codificare il file . Al suo interno è dichiarato il metodo Encode che utilizza due campi, il primo si riferisce al nome del file che deve essere codificato e che quindi viene aperto in lettura, il secondo campo si riferisce al nome del file codificato, chiamato Encoded_File.huf, dove huf indica Huffman File,e che quindi verrà aperto in scrittura. Questo metodo prevede anche la lettura del file sorgente con prelievo di infomazioni, istanziamento di un albero, la codifica di un carattere per volta, scritta poi in codice del file compresso. L'albero viene poi percorso ricorsivamente in maniera Bottom-Up.

#Decoder
Permette di decodificare il file. Al suo interno è dichiarato il metodo Decode formato da due campi, il primo è per il nome del file codificato e viene aperto in lettura, il secondo campo è per il nome del file decodificato e viene aperto in scrittura. Vengono quindi aperti i file, ricostruito l'albero, decodificate le parole in codice prelevando un bit alla volta percorrendo radice-foglia, viene scritto il caratterecorrispondente nel file decodificato, chiamato Decrypted_File.dhuf . L'albero viene percorso in modo ricorsivo Top-Down

#Valuta_Compressione
Permette di calcolare la dimensione del file e il tasso di compressione. Al suo interno è dichiarato il metodo Valuta_Compressione che ha due campi, il primo è per il file inserito in input, ovvero quello che deve essere compresso, il secondo si riferisce al file codificato. I due file vengono aperti e vengono calcolate le rispettive dimensioni in byte. Vengono quindi calcolate attraverso delle formule il tasso di compressione e lo spazio recuperato.
