#pragma once
#include "cpu.h"
#include "ppu.h"



class Gameboy {

public:

	CPU cpu;
	PPU ppu;
	Memory memory;

	int totalCycles = 0;
	std::string RomFilename;


	enum Buttons {
		down, up, left, right, start, select, B, A
	};

	int elapsedFrames = 0;
	bool redrawScreen = false;


	Gameboy(std::string Filename);
	~Gameboy();

	void Advance(int clockCount);
	void SetButtonState(Buttons button, bool pressed);
	byte* GetScreenPixels();
	byte* GetBackgroundPixels();
	byte* GetTilePixels();
	byte* GetColorPalettePixels();

	void SaveState(int stateNumber);
	void LoadState(int stateNumber);
};
