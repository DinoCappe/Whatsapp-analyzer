# Whatsapp-analyzer
A simple program to analyze a whatsapp chat
<br/>
- Come funziona il programma: data in input una chat whatsapp (vedi sotto come) il programma è in grado di contare il numero totale di messaggi nella chat e di catalogarli nelle seguenti categorie: <ul><li> foto </li><li> video </li><li> sticker </li><li> audio </li></ul> NB: sono inclusi in foto e video anche quelli ad una sola visualizzazione
- Come analizzare una chat: è necessario da applicazione smartphone selezionare la chat di interesse e selezionare il comando <strong>Esporta chat</strong> scegliendo l'opzione <strong>Senza media</strong>. A questo punto verrà creato un file zip contenente le trascrizioni di tutta la chat, sarà necessario estrarlo (unzipparlo) in modo da ottenere un file di testo (.txt). Questo sarà il file che il programma è in grado di analizzare.
- Come avviare il programma: il programma utilizza un'interfaccia a riga di comando e necessita di essere compilato in locale prima di essere utilizzato. Sarà quindi necessario posizionarsi nella cartella in cui si vuole installare ed eseguire il programma e scrivere il comando <code> g++ analyzeChat.cpp </code>. Successivamente assicurandosi che il file ottenuto dal punto precedente si trovi nella stessa cartella in cui si è installato il programma scrivere il comando <code> ./a.out _chat.txt nickname</code> in cui _chat.txt dovrà essere il nome del file e nickname il nome che si vuole associare alla chat. NB: Per successivi usi del programma è sufficiente eseguire solo il secondo comando
- Come leggere i risultati: se l'elaborazione fatta nel punto precedente è andata a buon fine verrà prodotto un file <code>output.txt</code> che conterrà l'esito dell'elaborazione. Nel caso in cui si effettui più di una elaborazione i risultati verranno aggiunti in coda a quelli già presenti, perciò per cancellare i precedenti risultati sarà sufficiente rimuoverli manualmente oppure eliminando direttamente il file di testo.
