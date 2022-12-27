#include <conio.h>     /* include for kbhit() and getch() functions */
#include <iostream>
#include <windows.h>   /* required before including mmsystem.h */
#include <mmsystem.h>  /* multimedia functions (such as MIDI) for Windows */
#include <atlstr.h>
#pragma comment(lib, "Winmm.lib") //Link the Winmm.lib to the EXE
using namespace std;

inline int MidiPlayFile(string filePath)
{
	CString commandString = ("play " + filePath).c_str();
	LPCTSTR command = commandString;
	//Now to play the song//
	mciSendStringW(command, NULL, NULL, NULL);
	return _getch();//Wait for song to finish

}

inline int MidiNoteExample()
{
	// storage for the current keyboard key being pressed
	int note = 0;
	int notestate = 0;  // keeping track of when the note is on or off
	int velocity = 100; // MIDI note velocity parameter value
	int midiport;       // select which MIDI output port to open
	int flag;           // monitor the status of returning functions
	HMIDIOUT device;    // MIDI device interface for sending MIDI output

	// variable which is both an integer and an array of characters:
	union { unsigned long word; unsigned char data[4]; } message;

	message.data[0] = 0x90;  // MIDI note-on message (requires to data bytes)
	message.data[1] = 60;    // MIDI note-on message: Key number (60 = middle C)
	message.data[2] = 110;   // MIDI note-on message: Key velocity (100 = loud)
	message.data[3] = 0;     // Unused parameter


	midiport = 0;


	// Open the MIDI output port
	flag = midiOutOpen(&device, midiport, 0, 0, CALLBACK_NULL);
	if (flag != MMSYSERR_NOERROR) {//Check if there is an error opening the port
		printf("Error opening MIDI Output.\n");//Exit if there is
		return 1;
	}

	cout << "Please enter the maximum value of note. (MIDI has a range of 0 to 127)\t";//Get the highest note value
	cin >> note;


	for (int x = 0x00; x <= note; x++)//run for loop to play each note
	{
		cout << "Playing Note number: " << x;//Say which number to play
		if (x % 3 == 0)//set to newline if it's been three times
		{
			cout << endl;
		}
		else
		{
			cout << "\t";
		}//Otherwise tab
		message.data[1] = x;//Set the note to be played out
		flag = midiOutShortMsg(device, message.word);//Play the note 
		if (flag != MMSYSERR_NOERROR) {//exit if error
			printf("Warning: MIDI Output is not open.\n");
		}

		Sleep(500);//wait 500 mS to hear note.
		message.data[1] = 0;//Set note to off
		flag = midiOutShortMsg(device, message.word);//set changes
		if (flag != MMSYSERR_NOERROR) {
			printf("Warning: MIDI Output is not open.\n");
		}
		Sleep(200);//wait 200mS until playing another note
	}

	// turn any MIDI notes currently playing:
	midiOutReset(device);

	// Remove any data in MIDI device and close the MIDI Output port
	midiOutClose(device);
	cout << endl << "All done! Press 'Enter'";
	return _getch();//wait to exit

}