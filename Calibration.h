//
//    Copyright 2004-2010 Thomas C. McDermott, N5EG
//    This file is part of VNAR - the Vector Network Analyzer program.
//
//    VNAR is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    VNAR is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with VNAR, if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//

#pragma once
#include "DisplayRoutines.h"
#include "USB_EZ_interface.h"
#include "Constants.h"
#include "Mockup.h"
#include <math.h>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace VNAR3
{

	/// <summary> 
	/// Summary for Calibration
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>

	/// Fixture Calibration
	public ref class Calibration : public System::Windows::Forms::Form
	{
	public: 
		Calibration(InstrumentCalDataSet^ CalDS,	///< Instrument Calibration Dataset
			 VNADevice^ VNADev,			///< VNA Hardware Device
			 FrequencyGrid^ fg)			///< Frequency Grid of parent
		{
			InitializeComponent();
			VNA = VNADev;			///< VNA hardware device
			Cal = CalDS;			///< Calibration Dataset
			FG = fg;				///< Frequency Grid

			BufferI = gcnew array<Int32>(CALSUM);
			BufferQ = gcnew array<Int32>(CALSUM);
			BufferM = gcnew array<Int32>(CALSUM);
			BufferN = gcnew array<Int32>(CALSUM);
			BufferP = gcnew array<Int32>(CALSUM);
			BufferR = gcnew array<Int32>(CALSUM);
			BufferS = gcnew array<Int32>(CALSUM);
		}
        
	protected: 
		~Calibration()
		{
			if(components)
				delete(components);
		}
	private: System::Windows::Forms::Button^  shortCal;
	private: System::Windows::Forms::Button^  openCal;
	private: System::Windows::Forms::Button^  termCal;
	private: System::Windows::Forms::Button^  thruCal;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  CancelButton;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  statShort;
	private: System::Windows::Forms::Button^  calSave;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  statOpen;
	private: System::Windows::Forms::Label^  statTerm;
	private: System::Windows::Forms::Label^  statThru;
	private: System::Windows::Forms::ProgressBar^  calProgressBar;
	private: System::Windows::Forms::GroupBox^  LinLogBox;
	private: System::Windows::Forms::RadioButton^  LogFreqButton;
	private: System::Windows::Forms::RadioButton^  LinearFreqButton;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  maxFreq;
	private: System::Windows::Forms::Label^  statThruF;
	private: System::Windows::Forms::Label^  statTermF;
	private: System::Windows::Forms::Label^  statOpenF;
	private: System::Windows::Forms::Label^  statShortF;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  minFreq;
	private: System::Windows::Forms::TextBox^  refPlaneBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  shortL0Box;
	private: System::Windows::Forms::TextBox^  shortLengthBox;
	private: System::Windows::Forms::TextBox^  openLengthBox;



	private: System::Windows::Forms::TextBox^  openC0Box;
	private: System::Windows::Forms::TextBox^  loadL0Box;
	private: System::Windows::Forms::Button^  applyButton;
	private: System::Windows::Forms::TextBox^  openC1Box;
	private: System::Windows::Forms::TextBox^  shortL1Box;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::TextBox^  openC2Box;
	private: System::Windows::Forms::TextBox^  shortL2Box;
	private: System::Windows::Forms::Label^  label20;
	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::TextBox^  loadR0Box;
	private: System::Windows::Forms::Label^  label18;
	private: System::Windows::Forms::TextBox^  loadLengthBox;
	private: System::Windows::Forms::Label^  label21;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Calibration::typeid));
			this->shortCal = (gcnew System::Windows::Forms::Button());
			this->openCal = (gcnew System::Windows::Forms::Button());
			this->termCal = (gcnew System::Windows::Forms::Button());
			this->thruCal = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->CancelButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->statShort = (gcnew System::Windows::Forms::Label());
			this->calSave = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->statOpen = (gcnew System::Windows::Forms::Label());
			this->statTerm = (gcnew System::Windows::Forms::Label());
			this->statThru = (gcnew System::Windows::Forms::Label());
			this->calProgressBar = (gcnew System::Windows::Forms::ProgressBar());
			this->LinLogBox = (gcnew System::Windows::Forms::GroupBox());
			this->LogFreqButton = (gcnew System::Windows::Forms::RadioButton());
			this->LinearFreqButton = (gcnew System::Windows::Forms::RadioButton());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->maxFreq = (gcnew System::Windows::Forms::TextBox());
			this->statThruF = (gcnew System::Windows::Forms::Label());
			this->statTermF = (gcnew System::Windows::Forms::Label());
			this->statOpenF = (gcnew System::Windows::Forms::Label());
			this->statShortF = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->minFreq = (gcnew System::Windows::Forms::TextBox());
			this->refPlaneBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->shortL0Box = (gcnew System::Windows::Forms::TextBox());
			this->shortLengthBox = (gcnew System::Windows::Forms::TextBox());
			this->openLengthBox = (gcnew System::Windows::Forms::TextBox());
			this->openC0Box = (gcnew System::Windows::Forms::TextBox());
			this->loadL0Box = (gcnew System::Windows::Forms::TextBox());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			this->openC1Box = (gcnew System::Windows::Forms::TextBox());
			this->shortL1Box = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->openC2Box = (gcnew System::Windows::Forms::TextBox());
			this->shortL2Box = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->loadR0Box = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->loadLengthBox = (gcnew System::Windows::Forms::TextBox());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->LinLogBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// shortCal
			// 
			this->shortCal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->shortCal->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->shortCal->Location = System::Drawing::Point(408, 281);
			this->shortCal->Name = L"shortCal";
			this->shortCal->Size = System::Drawing::Size(184, 40);
			this->shortCal->TabIndex = 0;
			this->shortCal->Text = L"\"Short\" Calibration";
			this->shortCal->Click += gcnew System::EventHandler(this, &Calibration::shortCal_Click);
			// 
			// openCal
			// 
			this->openCal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->openCal->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->openCal->Location = System::Drawing::Point(408, 337);
			this->openCal->Name = L"openCal";
			this->openCal->Size = System::Drawing::Size(184, 40);
			this->openCal->TabIndex = 1;
			this->openCal->Text = L"\"Open\" Calibration";
			this->openCal->Click += gcnew System::EventHandler(this, &Calibration::openCal_Click);
			// 
			// termCal
			// 
			this->termCal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->termCal->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->termCal->Location = System::Drawing::Point(408, 393);
			this->termCal->Name = L"termCal";
			this->termCal->Size = System::Drawing::Size(184, 40);
			this->termCal->TabIndex = 2;
			this->termCal->Text = L"\"50-ohm Term\" Calibration";
			this->termCal->Click += gcnew System::EventHandler(this, &Calibration::termCal_Click);
			// 
			// thruCal
			// 
			this->thruCal->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->thruCal->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->thruCal->Location = System::Drawing::Point(408, 449);
			this->thruCal->Name = L"thruCal";
			this->thruCal->Size = System::Drawing::Size(184, 40);
			this->thruCal->TabIndex = 3;
			this->thruCal->Text = L"\"Through\" Calibration";
			this->thruCal->Click += gcnew System::EventHandler(this, &Calibration::thruCal_Click);
			// 
			// label1
			// 
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Verdana", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(192, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(248, 23);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Fixture Calibration";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// CancelButton
			// 
			this->CancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->CancelButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->CancelButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CancelButton->Location = System::Drawing::Point(496, 503);
			this->CancelButton->Name = L"CancelButton";
			this->CancelButton->Size = System::Drawing::Size(96, 23);
			this->CancelButton->TabIndex = 6;
			this->CancelButton->Text = L"Cancel";
			// 
			// label2
			// 
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Location = System::Drawing::Point(112, 289);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(272, 32);
			this->label2->TabIndex = 7;
			this->label2->Text = L"1. Connect \'short\' to TX at measurement plane.";
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label3->Location = System::Drawing::Point(112, 345);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(272, 32);
			this->label3->TabIndex = 8;
			this->label3->Text = L"2. Connect \'open\' to TX at measurement plane.";
			// 
			// label4
			// 
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label4->Location = System::Drawing::Point(112, 401);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(272, 32);
			this->label4->TabIndex = 9;
			this->label4->Text = L"3. Connect \'50-ohm termination\' to TX at measurement plane.";
			// 
			// label5
			// 
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(112, 457);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(280, 32);
			this->label5->TabIndex = 10;
			this->label5->Text = L"4. Connect TX through to RX at measurement plane.";
			// 
			// statShort
			// 
			this->statShort->BackColor = System::Drawing::Color::Transparent;
			this->statShort->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statShort.Image")));
			this->statShort->Location = System::Drawing::Point(32, 289);
			this->statShort->Name = L"statShort";
			this->statShort->Size = System::Drawing::Size(32, 32);
			this->statShort->TabIndex = 11;
			this->statShort->Visible = false;
			// 
			// calSave
			// 
			this->calSave->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->calSave->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->calSave->Location = System::Drawing::Point(115, 503);
			this->calSave->Name = L"calSave";
			this->calSave->Size = System::Drawing::Size(152, 24);
			this->calSave->TabIndex = 15;
			this->calSave->Text = L"Save Cal Results...";
			this->calSave->Click += gcnew System::EventHandler(this, &Calibration::calSave_Click);
			// 
			// label6
			// 
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(24, 257);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 23);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Status";
			// 
			// statOpen
			// 
			this->statOpen->BackColor = System::Drawing::Color::Transparent;
			this->statOpen->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statOpen.Image")));
			this->statOpen->Location = System::Drawing::Point(32, 345);
			this->statOpen->Name = L"statOpen";
			this->statOpen->Size = System::Drawing::Size(32, 32);
			this->statOpen->TabIndex = 17;
			this->statOpen->Visible = false;
			// 
			// statTerm
			// 
			this->statTerm->BackColor = System::Drawing::Color::Transparent;
			this->statTerm->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statTerm.Image")));
			this->statTerm->Location = System::Drawing::Point(32, 401);
			this->statTerm->Name = L"statTerm";
			this->statTerm->Size = System::Drawing::Size(32, 32);
			this->statTerm->TabIndex = 18;
			this->statTerm->Visible = false;
			// 
			// statThru
			// 
			this->statThru->BackColor = System::Drawing::Color::Transparent;
			this->statThru->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statThru.Image")));
			this->statThru->Location = System::Drawing::Point(32, 457);
			this->statThru->Name = L"statThru";
			this->statThru->Size = System::Drawing::Size(32, 32);
			this->statThru->TabIndex = 19;
			this->statThru->Visible = false;
			// 
			// calProgressBar
			// 
			this->calProgressBar->Location = System::Drawing::Point(112, 543);
			this->calProgressBar->Maximum = 1024;
			this->calProgressBar->Name = L"calProgressBar";
			this->calProgressBar->Size = System::Drawing::Size(480, 16);
			this->calProgressBar->TabIndex = 20;
			// 
			// LinLogBox
			// 
			this->LinLogBox->BackColor = System::Drawing::Color::Transparent;
			this->LinLogBox->Controls->Add(this->LogFreqButton);
			this->LinLogBox->Controls->Add(this->LinearFreqButton);
			this->LinLogBox->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LinLogBox->Location = System::Drawing::Point(112, 61);
			this->LinLogBox->Name = L"LinLogBox";
			this->LinLogBox->Size = System::Drawing::Size(443, 73);
			this->LinLogBox->TabIndex = 21;
			this->LinLogBox->TabStop = false;
			this->LinLogBox->Text = L"Linear / Log Frequency Grid";
			// 
			// LogFreqButton
			// 
			this->LogFreqButton->AutoSize = true;
			this->LogFreqButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LogFreqButton->Location = System::Drawing::Point(7, 43);
			this->LogFreqButton->Name = L"LogFreqButton";
			this->LogFreqButton->Size = System::Drawing::Size(420, 20);
			this->LogFreqButton->TabIndex = 1;
			this->LogFreqButton->TabStop = true;
			this->LogFreqButton->Text = L"Use Log Frequency Grid for Fixture Calibration (constant Q)";
			this->LogFreqButton->UseVisualStyleBackColor = true;
			this->LogFreqButton->CheckedChanged += gcnew System::EventHandler(this, &Calibration::FreqModeChanged);
			// 
			// LinearFreqButton
			// 
			this->LinearFreqButton->AutoSize = true;
			this->LinearFreqButton->Checked = true;
			this->LinearFreqButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->LinearFreqButton->Location = System::Drawing::Point(7, 20);
			this->LinearFreqButton->Name = L"LinearFreqButton";
			this->LinearFreqButton->Size = System::Drawing::Size(408, 20);
			this->LinearFreqButton->TabIndex = 0;
			this->LinearFreqButton->TabStop = true;
			this->LinearFreqButton->Text = L"Use Linear Frequency Grid for Fixture Calibration (default)";
			this->LinearFreqButton->UseVisualStyleBackColor = true;
			this->LinearFreqButton->CheckedChanged += gcnew System::EventHandler(this, &Calibration::FreqModeChanged);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Location = System::Drawing::Point(112, 259);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(156, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"Maximum Calibration Frequency";
			// 
			// maxFreq
			// 
			this->maxFreq->Location = System::Drawing::Point(408, 255);
			this->maxFreq->Name = L"maxFreq";
			this->maxFreq->Size = System::Drawing::Size(184, 20);
			this->maxFreq->TabIndex = 23;
			this->maxFreq->Leave += gcnew System::EventHandler(this, &Calibration::maxFreq_Leave);
			// 
			// statThruF
			// 
			this->statThruF->BackColor = System::Drawing::Color::Transparent;
			this->statThruF->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statThruF.Image")));
			this->statThruF->Location = System::Drawing::Point(32, 457);
			this->statThruF->Name = L"statThruF";
			this->statThruF->Size = System::Drawing::Size(32, 32);
			this->statThruF->TabIndex = 24;
			this->statThruF->Visible = false;
			// 
			// statTermF
			// 
			this->statTermF->BackColor = System::Drawing::Color::Transparent;
			this->statTermF->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statTermF.Image")));
			this->statTermF->Location = System::Drawing::Point(32, 401);
			this->statTermF->Name = L"statTermF";
			this->statTermF->Size = System::Drawing::Size(32, 32);
			this->statTermF->TabIndex = 25;
			this->statTermF->Visible = false;
			// 
			// statOpenF
			// 
			this->statOpenF->BackColor = System::Drawing::Color::Transparent;
			this->statOpenF->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statOpenF.Image")));
			this->statOpenF->Location = System::Drawing::Point(32, 345);
			this->statOpenF->Name = L"statOpenF";
			this->statOpenF->Size = System::Drawing::Size(32, 32);
			this->statOpenF->TabIndex = 26;
			this->statOpenF->Visible = false;
			// 
			// statShortF
			// 
			this->statShortF->BackColor = System::Drawing::Color::Transparent;
			this->statShortF->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"statShortF.Image")));
			this->statShortF->Location = System::Drawing::Point(32, 289);
			this->statShortF->Name = L"statShortF";
			this->statShortF->Size = System::Drawing::Size(32, 32);
			this->statShortF->TabIndex = 27;
			this->statShortF->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Location = System::Drawing::Point(112, 232);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(153, 13);
			this->label8->TabIndex = 28;
			this->label8->Text = L"Minimum Calibration Frequency";
			// 
			// minFreq
			// 
			this->minFreq->Location = System::Drawing::Point(408, 229);
			this->minFreq->Name = L"minFreq";
			this->minFreq->Size = System::Drawing::Size(184, 20);
			this->minFreq->TabIndex = 29;
			this->minFreq->Leave += gcnew System::EventHandler(this, &Calibration::minFreq_Leave);
			// 
			// refPlaneBox
			// 
			this->refPlaneBox->Location = System::Drawing::Point(521, 35);
			this->refPlaneBox->Name = L"refPlaneBox";
			this->refPlaneBox->Size = System::Drawing::Size(71, 20);
			this->refPlaneBox->TabIndex = 36;
			this->refPlaneBox->Text = L"0";
			this->refPlaneBox->TextChanged += gcnew System::EventHandler(this, &Calibration::refPlaneBox_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BackColor = System::Drawing::Color::Transparent;
			this->label9->Location = System::Drawing::Point(155, 135);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 13);
			this->label9->TabIndex = 37;
			this->label9->Text = L"Short";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->Location = System::Drawing::Point(298, 135);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 13);
			this->label10->TabIndex = 38;
			this->label10->Text = L"Open";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Transparent;
			this->label11->Location = System::Drawing::Point(447, 134);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(31, 13);
			this->label11->TabIndex = 39;
			this->label11->Text = L"Load";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Transparent;
			this->label12->Location = System::Drawing::Point(112, 207);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 40;
			this->label12->Text = L"Length";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Transparent;
			this->label13->Location = System::Drawing::Point(262, 207);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(40, 13);
			this->label13->TabIndex = 41;
			this->label13->Text = L"Length";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Transparent;
			this->label14->Location = System::Drawing::Point(133, 153);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(19, 13);
			this->label14->TabIndex = 42;
			this->label14->Text = L"L0";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->BackColor = System::Drawing::Color::Transparent;
			this->label15->Location = System::Drawing::Point(410, 170);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(19, 13);
			this->label15->TabIndex = 43;
			this->label15->Text = L"L0";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->BackColor = System::Drawing::Color::Transparent;
			this->label16->Location = System::Drawing::Point(275, 153);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(20, 13);
			this->label16->TabIndex = 44;
			this->label16->Text = L"C0";
			// 
			// shortL0Box
			// 
			this->shortL0Box->Location = System::Drawing::Point(158, 150);
			this->shortL0Box->Name = L"shortL0Box";
			this->shortL0Box->Size = System::Drawing::Size(104, 20);
			this->shortL0Box->TabIndex = 45;
			// 
			// shortLengthBox
			// 
			this->shortLengthBox->Location = System::Drawing::Point(158, 204);
			this->shortLengthBox->Name = L"shortLengthBox";
			this->shortLengthBox->Size = System::Drawing::Size(104, 20);
			this->shortLengthBox->TabIndex = 46;
			// 
			// openLengthBox
			// 
			this->openLengthBox->Location = System::Drawing::Point(301, 204);
			this->openLengthBox->Name = L"openLengthBox";
			this->openLengthBox->Size = System::Drawing::Size(104, 20);
			this->openLengthBox->TabIndex = 47;
			// 
			// openC0Box
			// 
			this->openC0Box->Location = System::Drawing::Point(301, 150);
			this->openC0Box->Name = L"openC0Box";
			this->openC0Box->Size = System::Drawing::Size(104, 20);
			this->openC0Box->TabIndex = 48;
			// 
			// loadL0Box
			// 
			this->loadL0Box->Location = System::Drawing::Point(450, 167);
			this->loadL0Box->Name = L"loadL0Box";
			this->loadL0Box->Size = System::Drawing::Size(104, 20);
			this->loadL0Box->TabIndex = 49;
			// 
			// applyButton
			// 
			this->applyButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->applyButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->applyButton->Font = (gcnew System::Drawing::Font(L"Verdana", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->applyButton->Location = System::Drawing::Point(333, 503);
			this->applyButton->Name = L"applyButton";
			this->applyButton->Size = System::Drawing::Size(96, 23);
			this->applyButton->TabIndex = 50;
			this->applyButton->Text = L"Apply";
			this->applyButton->Click += gcnew System::EventHandler(this, &Calibration::applyButton_Click);
			// 
			// openC1Box
			// 
			this->openC1Box->Location = System::Drawing::Point(301, 167);
			this->openC1Box->Name = L"openC1Box";
			this->openC1Box->Size = System::Drawing::Size(104, 20);
			this->openC1Box->TabIndex = 55;
			// 
			// shortL1Box
			// 
			this->shortL1Box->Location = System::Drawing::Point(158, 167);
			this->shortL1Box->Name = L"shortL1Box";
			this->shortL1Box->Size = System::Drawing::Size(104, 20);
			this->shortL1Box->TabIndex = 54;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->BackColor = System::Drawing::Color::Transparent;
			this->label17->Location = System::Drawing::Point(275, 170);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 13);
			this->label17->TabIndex = 53;
			this->label17->Text = L"C1";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->BackColor = System::Drawing::Color::Transparent;
			this->label19->Location = System::Drawing::Point(133, 170);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(19, 13);
			this->label19->TabIndex = 51;
			this->label19->Text = L"L1";
			// 
			// openC2Box
			// 
			this->openC2Box->Location = System::Drawing::Point(301, 184);
			this->openC2Box->Name = L"openC2Box";
			this->openC2Box->Size = System::Drawing::Size(104, 20);
			this->openC2Box->TabIndex = 61;
			// 
			// shortL2Box
			// 
			this->shortL2Box->Location = System::Drawing::Point(158, 184);
			this->shortL2Box->Name = L"shortL2Box";
			this->shortL2Box->Size = System::Drawing::Size(104, 20);
			this->shortL2Box->TabIndex = 60;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->BackColor = System::Drawing::Color::Transparent;
			this->label20->Location = System::Drawing::Point(275, 187);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(20, 13);
			this->label20->TabIndex = 59;
			this->label20->Text = L"C2";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->BackColor = System::Drawing::Color::Transparent;
			this->label22->Location = System::Drawing::Point(133, 187);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(19, 13);
			this->label22->TabIndex = 57;
			this->label22->Text = L"L2";
			// 
			// loadR0Box
			// 
			this->loadR0Box->Location = System::Drawing::Point(450, 150);
			this->loadR0Box->Name = L"loadR0Box";
			this->loadR0Box->Size = System::Drawing::Size(104, 20);
			this->loadR0Box->TabIndex = 62;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->BackColor = System::Drawing::Color::Transparent;
			this->label18->Location = System::Drawing::Point(410, 153);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(21, 13);
			this->label18->TabIndex = 63;
			this->label18->Text = L"R0";
			// 
			// loadLengthBox
			// 
			this->loadLengthBox->Location = System::Drawing::Point(450, 204);
			this->loadLengthBox->Name = L"loadLengthBox";
			this->loadLengthBox->Size = System::Drawing::Size(104, 20);
			this->loadLengthBox->TabIndex = 64;
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->BackColor = System::Drawing::Color::Transparent;
			this->label21->Location = System::Drawing::Point(410, 207);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(40, 13);
			this->label21->TabIndex = 65;
			this->label21->Text = L"Length";
			// 
			// Calibration
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(638, 571);
			this->Controls->Add(this->label21);
			this->Controls->Add(this->loadLengthBox);
			this->Controls->Add(this->label18);
			this->Controls->Add(this->loadR0Box);
			this->Controls->Add(this->openC2Box);
			this->Controls->Add(this->shortL2Box);
			this->Controls->Add(this->label20);
			this->Controls->Add(this->label22);
			this->Controls->Add(this->openC1Box);
			this->Controls->Add(this->shortL1Box);
			this->Controls->Add(this->label17);
			this->Controls->Add(this->label19);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->loadL0Box);
			this->Controls->Add(this->openC0Box);
			this->Controls->Add(this->openLengthBox);
			this->Controls->Add(this->shortLengthBox);
			this->Controls->Add(this->shortL0Box);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->refPlaneBox);
			this->Controls->Add(this->minFreq);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->statShortF);
			this->Controls->Add(this->statOpenF);
			this->Controls->Add(this->statTermF);
			this->Controls->Add(this->statThruF);
			this->Controls->Add(this->maxFreq);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->LinLogBox);
			this->Controls->Add(this->calProgressBar);
			this->Controls->Add(this->statThru);
			this->Controls->Add(this->statTerm);
			this->Controls->Add(this->statOpen);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->calSave);
			this->Controls->Add(this->statShort);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->CancelButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->thruCal);
			this->Controls->Add(this->termCal);
			this->Controls->Add(this->openCal);
			this->Controls->Add(this->shortCal);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Name = L"Calibration";
			this->Text = L"Calibration";
			this->Load += gcnew System::EventHandler(this, &Calibration::Calibration_Load);
			this->LinLogBox->ResumeLayout(false);
			this->LinLogBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}		

		private: VNADevice^ VNA;		///< Vector Network Analyzer hardware object
		private: FrequencyGrid^ FG;		///< Our Frequency Grid
		private: InstrumentCalDataSet^ Cal;		///< Calibration Data Set for the instrument
		public: SaveFileDialog^ outfile;	///< Saved File Structure

		array<Int32>^ BufferI;			///< Holds raw readings from VNA during data collection
		array<Int32>^ BufferQ;
		array<Int32>^ BufferM;
		array<Int32>^ BufferN;
		array<Int32>^ BufferP;
		array<Int32>^ BufferR;
		array<Int32>^ BufferS;

		/// Fixture SHORTed Load Calibration button click handler
	private: System::Void shortCal_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				long i;
				VNA_RXBUFFER *RxBuf = new VNA_RXBUFFER;
				VNA_TXBUFFER *TxBuf = new VNA_TXBUFFER;
				double fmagnitude;			// 0 to 1
				double fphase;				// -180 to +180	
				double& rmag = fmagnitude;
				double& rphs = fphase;
				MeasurementSet^ calPoint = gcnew MeasurementSet;
				//VNA->SetMode(M_SHORT);

				VNA->Sweep(Cal->GetFreqFromFixtureCalGrid(0, false), Cal->GetFreqFromFixtureCalGrid(1, false) - Cal->GetFreqFromFixtureCalGrid(0, false), PHASECALGRIDSIZE, CALSUM, calProgressBar);
				for (i=0; i<PHASECALGRIDSIZE; i++)
				{
					// Compute spot frequency

					__int64 Fdesired;
					Fdesired = Cal->GetFreqFromFixtureCalGrid(i, LogFreqButton->Checked);

					TxBuf->TxAccum = i; //FG->DDS(Fdesired);		
					TxBuf->IDAClevelHi = MAX_DDS_LEVEL;		// Max transmit level
					TxBuf->ReplyType = 0;
					TxBuf->MeasureDelay = 0;
					TxBuf->QDAClevel = QDAC_ZERODBM;	// Reference level


                    if (!VNA->WriteRead(TxBuf, RxBuf,DIR_REFL)) {
						statShortF->Visible = true;
					  goto done;
					}
//					calPoint->ReflPI = RxBuf->ReflPI;
					calPoint->ReflPQ = RxBuf->ReflPQ;
					calPoint->ReflMQ = RxBuf->ReflMQ;

					Cal->ResolveReflPolar(calPoint, Fdesired, rmag, rphs, true);

					// convert it to rectangular
					double fx = fmagnitude * cos(fphase * DEGR2RAD);
					double fy = fmagnitude * sin(fphase * DEGR2RAD);

					// save it as S11-meas-short
					Cal->S11shortReal[i] = fx; Cal->S11shortImag[i] = fy;

					calProgressBar->Value = i;
					if(i%20 == 0)
						calProgressBar->Update();
				}
				if (i == PHASECALGRIDSIZE) {
					statShort->Visible = true;
					statShortF->Visible = false;
				}
			done:
				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;

			 }

		/// Fixture OPEN Load Calibration button click handler
	private: System::Void openCal_Click(System::Object^  sender, System::EventArgs^  e)
			{
				long i;
				VNA_RXBUFFER *RxBuf = new VNA_RXBUFFER;
				VNA_TXBUFFER *TxBuf = new VNA_TXBUFFER;
				double fmagnitude;			// 0 to 1
				double fphase;				// -180 to +180	
				double& rmag = fmagnitude;
				double& rphs = fphase;
				MeasurementSet^ calPoint = gcnew MeasurementSet;
				//VNA->SetMode(M_OPEN);

				 // run a sweep of 1024 points, collecting S11 data 'short'
				VNA->Sweep(Cal->GetFreqFromFixtureCalGrid(0, false), Cal->GetFreqFromFixtureCalGrid(1, false) - Cal->GetFreqFromFixtureCalGrid(0, false), PHASECALGRIDSIZE, CALSUM, calProgressBar);
				for (i=0; i<PHASECALGRIDSIZE; i++)
				{
					// Compute spot frequency

					__int64 Fdesired;
					Fdesired = Cal->GetFreqFromFixtureCalGrid(i, LogFreqButton->Checked);

					TxBuf->TxAccum = i;  //FG->DDS(Fdesired);		
					TxBuf->IDAClevelHi = MAX_DDS_LEVEL;		// Max transmit level
					TxBuf->ReplyType = 0;
					TxBuf->MeasureDelay = 0;
					TxBuf->QDAClevel = QDAC_ZERODBM;	// Reference level


                    if (!VNA->WriteRead(TxBuf, RxBuf,DIR_REFL)) {
					  statOpenF->Visible = true;
					  goto done;
					}
//					calPoint->ReflPI = RxBuf->ReflPI;
					calPoint->ReflPQ = RxBuf->ReflPQ;
					calPoint->ReflMQ = RxBuf->ReflMQ;

					Cal->ResolveReflPolar(calPoint, Fdesired, rmag, rphs, true);

					// convert it to rectangular
					double fx = fmagnitude * cos(fphase * DEGR2RAD);
					double fy = fmagnitude * sin(fphase * DEGR2RAD);

					// save it as S11-meas-open
					Cal->S11openReal[i] = fx; Cal->S11openImag[i] = fy;

					calProgressBar->Value = i;
					if(i%20 == 0)
						calProgressBar->Update();
				}
			done:
				if (i == PHASECALGRIDSIZE) {
					statOpen->Visible = true;
					statOpenF->Visible = false;
				}
				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;

			}

		/// Fixture TERMINATED Load Calibration button click handler
	private: System::Void termCal_Click(System::Object^  sender, System::EventArgs^  e)
			{
				long i;
				VNA_RXBUFFER *RxBuf = new VNA_RXBUFFER;
				VNA_TXBUFFER *TxBuf = new VNA_TXBUFFER;
				double fmagnitude;			// 0 to 1
				double fphase;				// -180 to +180	
				double& rmag = fmagnitude;
				double& rphs = fphase;
				MeasurementSet^ calPoint = gcnew MeasurementSet;

				//VNA->SetMode(M_LOAD);
				 // run a sweep of 1024 points, collecting S11 data 'short'

				VNA->Sweep(Cal->GetFreqFromFixtureCalGrid(0, false), Cal->GetFreqFromFixtureCalGrid(1, false) - Cal->GetFreqFromFixtureCalGrid(0, false), PHASECALGRIDSIZE, CALSUM, calProgressBar);
				for (i=0; i<PHASECALGRIDSIZE; i++)
				{
					// Compute spot frequency

					__int64 Fdesired;
					Fdesired = Cal->GetFreqFromFixtureCalGrid(i, LogFreqButton->Checked);

					TxBuf->TxAccum = i; //FG->DDS(Fdesired);		
					TxBuf->IDAClevelHi = MAX_DDS_LEVEL;		// Max transmit level
					TxBuf->ReplyType = 0;
					TxBuf->MeasureDelay = 0;
					TxBuf->QDAClevel = QDAC_ZERODBM;	// Reference level

                    if (!VNA->WriteRead(TxBuf, RxBuf,DIR_REFL)) {
						statTermF->Visible = true;
					  goto done;
					}
//					calPoint->ReflPI = RxBuf->ReflPI;
					calPoint->ReflPQ = RxBuf->ReflPQ;
					calPoint->ReflMQ = RxBuf->ReflMQ;

					Cal->ResolveReflPolar(calPoint, Fdesired, rmag, rphs, true);

					// convert it to rectangular
					double fx = fmagnitude * cos(fphase * DEGR2RAD);
					double fy = fmagnitude * sin(fphase * DEGR2RAD);

					// save it as S11-meas-short
					Cal->S11termReal[i] = fx; Cal->S11termImag[i] = fy;

					calProgressBar->Value = i;
					if(i%20 == 0)
						calProgressBar->Update();
				}
			done:
				if (i == PHASECALGRIDSIZE) {
					statTerm->Visible = true;
					statTermF->Visible = false;
				}
				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;

			}

		/// Fixture Through Calibration button click handler
	private: System::Void thruCal_Click(System::Object^  sender, System::EventArgs^  e)
			{
				long i;
				VNA_RXBUFFER *RxBuf = new VNA_RXBUFFER;
				VNA_TXBUFFER *TxBuf = new VNA_TXBUFFER;
				double fmagnitude;			// 0 to 1
				double fphase;				// -180 to +180	
				double& rmag = fmagnitude;
				double& rphs = fphase;
				MeasurementSet^ calPoint = gcnew MeasurementSet;

				//VNA->SetMode(M_THROUGH);

				// run a sweep of 1024 points, collecting S21 data 'thru'

				VNA->Sweep(Cal->GetFreqFromFixtureCalGrid(0, false), Cal->GetFreqFromFixtureCalGrid(1, false) - Cal->GetFreqFromFixtureCalGrid(0, false), PHASECALGRIDSIZE, CALSUM, calProgressBar);
				for (i=0; i<PHASECALGRIDSIZE; i++)
				{
					// Compute spot frequency

					__int64 Fdesired;
					Fdesired = Cal->GetFreqFromFixtureCalGrid(i, LogFreqButton->Checked);

					TxBuf->TxAccum = i; // FG->DDS(Fdesired);

					TxBuf->IDAClevelHi = TxLevLinear(0);	// Set High Tx Level
					TxBuf->IDAClevelLo = TxLevLinear(0 - TARGETLOMAG);	// Set Low TX Level
					TxBuf->IDAClevelMid = TxLevLinear(0 - TARGETMIDMAG);	// Set Mid TX Level

					// Set the Lo phase tran measurement level for the target   09-30-2007
					TxBuf->IDAClevelPhLow = TxLevLinear(0 - TARGETPHLOMAG);	// Set Lo Phase Level

					TxBuf->ReplyType = 0;
					TxBuf->MeasureDelay = 0;
					TxBuf->QDAClevel = QDAC_ZERODBM;	// Reference level


                    if (!VNA->WriteRead(TxBuf, RxBuf, DIR_TRANS)) {
						statThruF->Visible = true;
						goto done;
					}


//					calPoint->TranPI = RxBuf->TranPI;
					calPoint->TranPQ = RxBuf->TranPQ;
//					calPoint->TranMQHi = RxBuf->TranMQHi;
					calPoint->TranMQ = RxBuf->TranMQ;
//					calPoint->TranMQMid = RxBuf->TranMQMid;
//					calPoint->TranPILow = RxBuf->TranPILow;
//					calPoint->TranPQLow = RxBuf->TranPQLow;

					Cal->ResolveTranPolar(calPoint, Fdesired, rmag, rphs);

					// convert it to rectangular
					double fx = fmagnitude * cos(fphase * DEGR2RAD);
					double fy = fmagnitude * sin(fphase * DEGR2RAD);

					// save it as S21-meas-through
					Cal->S21termReal[i] = fx; Cal->S21termImag[i] = fy;

					Cal->ThReal[i] = fx; Cal->ThImag[i] = fy;

					calProgressBar->Value = i;
					if(i%20 == 0)
						calProgressBar->Update();
				}
			done:
				if (i == PHASECALGRIDSIZE) {
					statThru->Visible = true;
					statThruF->Visible = false;
				}
				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;

			}

		/// Fixture Save Calibration button click handler
	private: System::Void calSave_Click(System::Object^  sender, System::EventArgs^  e)
			{
				Cal->OpenC0 = Convert::ToDouble(openC0Box->Text);
				Cal->OpenC1 = Convert::ToDouble(openC1Box->Text);
				Cal->OpenC2 = Convert::ToDouble(openC2Box->Text);
				Cal->ShortL0 = Convert::ToDouble(shortL0Box->Text);
				Cal->ShortL1 = Convert::ToDouble(shortL1Box->Text);
				Cal->ShortL2 = Convert::ToDouble(shortL2Box->Text);
				Cal->OpenLength = Convert::ToDouble(openLengthBox->Text);
				Cal->ShortLength = Convert::ToDouble(shortLengthBox->Text);
				Cal->LoadL0 = Convert::ToDouble(loadL0Box->Text);
				Cal->LoadR0 = Convert::ToDouble(loadR0Box->Text);
				Cal->LoadLength = Convert::ToDouble(loadLengthBox->Text);

				// Compute Error Terms
				CalToErrorTerms(Cal);

				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;

				// Save results to file
				outfile = gcnew SaveFileDialog();
				outfile->Filter = "calibration files (*.cal)|*.cal";
				outfile->AddExtension = true;
				if (outfile->ShowDialog() == ::DialogResult::OK)
				{
					SaveCalDataSet(outfile, Cal);		// InstrumentCalDataSet holds Fixture CalData also.
														// Extract only Fixture CalData during save.
					DialogResult = ::DialogResult::OK;	// Let caller know that Fixture Cal saved a valid file
				}
				else
					DialogResult = ::DialogResult::Cancel;
			}


private: System::Void FreqModeChanged(System::Object^  sender, System::EventArgs^  e)
		 {
			 // user changed the Linear / Log Mode. Invalidate the calibrations.

			 statThru->Visible = false;
			 statTerm->Visible = false;
			 statOpen->Visible = false;
			 statShort->Visible = false;
			 statThruF->Visible = false;
			 statTermF->Visible = false;
			 statOpenF->Visible = false;
			 statShortF->Visible = false;

			 Refresh();
		 }


private: System::Void Calibration_Load(System::Object^  sender, System::EventArgs^  e) {
			minFreq->Text = String::Format("{0}",Cal->minCalFreq);
			maxFreq->Text = String::Format("{0}",Cal->maxCalFreq);
			refPlaneBox->Text = (Cal->reflTimeDelayEquivalent*1e12).ToString();
			openC0Box->Text = (Cal->OpenC0).ToString();
			openC1Box->Text = (Cal->OpenC1).ToString();
			openC2Box->Text = (Cal->OpenC2).ToString();
			shortL0Box->Text = (Cal->ShortL0).ToString();
			shortL1Box->Text = (Cal->ShortL1).ToString();
			shortL2Box->Text = (Cal->ShortL2).ToString();
			openLengthBox->Text = (Cal->OpenLength).ToString();
			shortLengthBox->Text = (Cal->ShortLength).ToString();
			loadL0Box->Text = (Cal->LoadL0).ToString();
			loadR0Box->Text = (Cal->LoadR0).ToString();
			loadLengthBox->Text = (Cal->LoadLength).ToString();
		 }

private: System::Void maxFreq_Leave(System::Object^  sender, System::EventArgs^  e) {
			__int64 freq;
			 try										// make sure it's an integer number
			{
				freq = Convert::ToInt64(maxFreq->Text);
				if (freq < VNA->GetMinFreq()) 
					MessageBox::Show("Frequency too low", "Error");
				else if (freq > VNA->GetMaxFreq())
					MessageBox::Show("Frequency too high", "Error");
				else {
					Cal->maxCalFreq = freq;
				}
			}
			catch (System::FormatException^ pe)
			{
				MessageBox::Show(pe->Message, "Error");
			}
			catch (System::OverflowException^ pe)
			{
				MessageBox::Show(pe->Message, "Error");
			}

		 }
private: System::Void minFreq_Leave(System::Object^  sender, System::EventArgs^  e) {
		__int64 freq;
			 try										// make sure it's an integer number
			{
				freq = Convert::ToInt64(minFreq->Text);
				if (freq <  VNA->GetMinFreq()) 
					MessageBox::Show("Frequency too low", "Error");
				else if (freq > VNA->GetMaxFreq())
					MessageBox::Show("Frequency too high", "Error");
				else {
					Cal->minCalFreq = freq;
				}
			}
			catch (System::FormatException^ pe)
			{
				MessageBox::Show(pe->Message, "Error");
			}
			catch (System::OverflowException^ pe)
			{
				MessageBox::Show(pe->Message, "Error");
			}


		 }
private: System::Void refPlaneBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
//			Cal->reflTimeDelayEquivalent = Convert::ToDouble(refPlaneBox->Text);
		 }
private: System::Void applyButton_Click(System::Object^  sender, System::EventArgs^  e) {
				Cal->OpenC0 = Convert::ToDouble(openC0Box->Text);
				Cal->OpenC1 = Convert::ToDouble(openC1Box->Text);
				Cal->OpenC2 = Convert::ToDouble(openC2Box->Text);
				Cal->ShortL0 = Convert::ToDouble(shortL0Box->Text);
				Cal->ShortL1 = Convert::ToDouble(shortL1Box->Text);
				Cal->ShortL2 = Convert::ToDouble(shortL2Box->Text);
				Cal->OpenLength = Convert::ToDouble(openLengthBox->Text);
				Cal->ShortLength = Convert::ToDouble(shortLengthBox->Text);
				Cal->LoadLength = Convert::ToDouble(loadLengthBox->Text);
				Cal->LoadL0 = Convert::ToDouble(loadL0Box->Text);
				Cal->LoadR0 = Convert::ToDouble(loadR0Box->Text);

				// Compute Error Terms
				CalToErrorTerms(Cal);

				// update the type of Fixture Calibration Frequency mode in the dataset
				Cal->FixtureCalLogFreqMode = LogFreqButton->Checked;
#if 0			// No save with Apply

				// Save results to file
				outfile = gcnew SaveFileDialog();
				outfile->Filter = "calibration files (*.cal)|*.cal";
				outfile->AddExtension = true;
				if (outfile->ShowDialog() == ::DialogResult::OK)
				{
					SaveCalDataSet(outfile, Cal);		// InstrumentCalDataSet holds Fixture CalData also.
														// Extract only Fixture CalData during save.
					DialogResult = ::DialogResult::OK;	// Let caller know that Fixture Cal saved a valid file
				}
				else
#endif
					DialogResult = ::DialogResult::Yes;

		 }
};
}