#include <string.h>

/* Makro zum Leeren des Streams stdin
   Das Makro liest aus dem Eingabepuffer der Tastatur
   alle Zeichen bis zu (char)10 einschliesslich.
   Das Makro darf nicht vor der ersten Eingabe aktiviert werden!  */
#define INCLR while (getchar()!='\12');

/* Makro zum Anhalten des Programms (z.B. am Programmende)
   Vorausgesetzt wird, dass der Eingabepuffer leer ist!  */
#define PAUSE printf("\nDruecken Sie die Eingabetaste . . .\n"); getchar();

/* Funktion zklesen zur Eingabe einer Zeichenkette von der Tastatur
   ohne Gefahr des buffer overflow
   Rueckgabewert:
   Anzahl der eingelesenen und gespeicherten Zeichen (ohne Terminator)
   Parameter:
   s     : Startadresse zum Abspeichern der Zeichenkette
   bytes : Groesse des bereitgestellten Speicherplatzes in Byte
   Die Funktion benoetigt die Headerdatei string.h .
   Nach Ablauf der Funktion ist der Eingabepuffer leer!                */
int zklesen(char* s, int bytes)
{
  int anz;
  fgets(s,bytes,stdin);
  anz=strlen(s);
  if (s[anz-1]=='\12') { anz--; s[anz]='\0'; }
  else { while (getchar()!='\12'); }
  return anz;
}

/* Funktion zur Ausgabe eines Wertes vom Typ unsigned long long
   mit Hilfe von printf */
void print_ulonglong(unsigned long long zahl)
{  
 int t1, t2, t3, zmax=1000000000;
 t3=zahl%zmax;
 zahl=zahl/zmax; 
 t2=zahl%zmax;
 zahl=zahl/zmax; 
 t1=zahl;
 if (t1>0) printf("%d%09d%09d",t1,t2,t3);
 else if (t2>0) printf("%d%09d",t2,t3);
      else printf("%d",t3);
}

/* Funktion zur Ausgabe eines Wertes vom Typ long long
   mit Hilfe von printf
   Benoetigt wird die Funktion print_ulonglong */
void print_longlong(long long zahl)
{  
 if (zahl<0LL) { printf("-"); zahl=-zahl; }
 print_ulonglong(zahl);
}
