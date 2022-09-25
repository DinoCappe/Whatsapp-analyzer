/* version 1.0 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv){
    if(argc != 3){
        cerr << "Correct invocation: " << argv[0] << " 'chat.txt' Name" << endl;
        exit(1);
    }
    fstream chat, output;
    chat.open(argv[1], ios::in);
    if(chat.fail()){
        cerr << "File " << argv[1] << " not found" << endl;
        exit(2);
    }
    string buffer;
    int messaggi = 0, foto = 0, video = 0, sticker = 0, audio = 0;
    while(getline(chat, buffer)){
        if(buffer.find("[") != string::npos){
            buffer = buffer.substr(buffer.find(": ") + 2);
            if(buffer.find("‎") == 0){
                buffer = buffer.substr(3);
            }/* il parsing funziona solo se la chat è stata scaricata da un client italiano
            ovvero i messaggi di sistema con cui vengono riconosciute le tipologie di messaggio
            sono in italiano. Implementazioni future potranno implementare anche la scelta della lingua*/
            if(buffer.find("I messaggi e le chiamate sono crittografati end-to-end") != 0){
                messaggi++;
                if(buffer.find("immagine omessa") == 0){
                    foto++;
                }else if(buffer.find("video omesso") == 0){
                    video++;
                }else if(buffer.find("sticker non incluso") == 0){
                    sticker++;
                }
                else if(buffer.find("audio omesso") == 0){
                    audio++;
                }
            }
        }
    }
    chat.close();
    output.open("output.txt", ios::app);
    output << "----------------" << endl << argv[2] << endl;
    output << "Messaggi: " << messaggi << " Foto: " << foto << " Video: " << video << " Sticker: " << sticker << " Audio: " << audio << endl;
    output << "----------------" << endl;
    output.close();
    return 0;
}
