#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "Corner.h"
#include "FocusController.h"
#include "ModeController.h"
#include "Ray.h"

namespace Project2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace std;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ErrorProvider^ errorProvider1;

	private: System::Windows::Forms::ColorDialog^ colorDialog1;

	private: System::Windows::Forms::OpenFileDialog^ openFileDialog;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog;
	private: System::Windows::Forms::PictureBox^ pictureMain;
	private: System::Windows::Forms::Button^ btnSaveAs;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::Button^ btnOpen;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Panel^ panelCorner;
	private: System::Windows::Forms::TextBox^ txtCornerY;
	private: System::Windows::Forms::TextBox^ txtCornerX;
	private: System::Windows::Forms::Label^ lblCornerY;
	private: System::Windows::Forms::Label^ lblCornerX;
	private: System::Windows::Forms::Panel^ panelMirror;
	private: System::Windows::Forms::RadioButton^ rbtnMirrorConcave;


	private: System::Windows::Forms::RadioButton^ rbtnMirrorConvex;

	private: System::Windows::Forms::Label^ lblMirrorType;

	private: System::Windows::Forms::RadioButton^ rbtnMirrorFlat;





	private: System::Windows::Forms::Label^ lblMirrorRadius;
	private: System::Windows::Forms::TextBox^ txtMirrorRadius;
	private: System::Windows::Forms::Button^ btnDivide;
	private: System::Windows::Forms::Button^ btnRemoveCorner;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::RadioButton^ rbtnModeRayCasting;

	private: System::Windows::Forms::RadioButton^ rbtnModeRoomEditing;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panelRay;

	private: System::Windows::Forms::TextBox^ txtAngle;
	private: System::Windows::Forms::Label^ lblAngle;
	private: System::Windows::Forms::Label^ lblMirrorOptions;

	private: System::Windows::Forms::Label^ lblCornerOptions;
	private: System::Windows::Forms::Label^ lblRayOptions;
	private: System::Windows::Forms::TextBox^ txtReflectionsCount;
	private: System::Windows::Forms::Label^ lblReflectionsCount;





	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->pictureMain = (gcnew System::Windows::Forms::PictureBox());
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnSaveAs = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelCorner = (gcnew System::Windows::Forms::Panel());
			this->lblCornerOptions = (gcnew System::Windows::Forms::Label());
			this->btnRemoveCorner = (gcnew System::Windows::Forms::Button());
			this->txtCornerY = (gcnew System::Windows::Forms::TextBox());
			this->txtCornerX = (gcnew System::Windows::Forms::TextBox());
			this->lblCornerY = (gcnew System::Windows::Forms::Label());
			this->lblCornerX = (gcnew System::Windows::Forms::Label());
			this->panelMirror = (gcnew System::Windows::Forms::Panel());
			this->lblMirrorOptions = (gcnew System::Windows::Forms::Label());
			this->btnDivide = (gcnew System::Windows::Forms::Button());
			this->lblMirrorRadius = (gcnew System::Windows::Forms::Label());
			this->txtMirrorRadius = (gcnew System::Windows::Forms::TextBox());
			this->rbtnMirrorConcave = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnMirrorConvex = (gcnew System::Windows::Forms::RadioButton());
			this->lblMirrorType = (gcnew System::Windows::Forms::Label());
			this->rbtnMirrorFlat = (gcnew System::Windows::Forms::RadioButton());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->rbtnModeRayCasting = (gcnew System::Windows::Forms::RadioButton());
			this->rbtnModeRoomEditing = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelRay = (gcnew System::Windows::Forms::Panel());
			this->txtReflectionsCount = (gcnew System::Windows::Forms::TextBox());
			this->lblReflectionsCount = (gcnew System::Windows::Forms::Label());
			this->lblRayOptions = (gcnew System::Windows::Forms::Label());
			this->txtAngle = (gcnew System::Windows::Forms::TextBox());
			this->lblAngle = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureMain))->BeginInit();
			this->panelCorner->SuspendLayout();
			this->panelMirror->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panelRay->SuspendLayout();
			this->SuspendLayout();
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// openFileDialog
			// 
			this->openFileDialog->DefaultExt = L"txt";
			this->openFileDialog->FileName = L"openFileDialog1";
			this->openFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*\"";
			this->openFileDialog->Title = L"Открыть файл";
			// 
			// saveFileDialog
			// 
			this->saveFileDialog->DefaultExt = L"txt";
			this->saveFileDialog->Filter = L"Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*\"";
			this->saveFileDialog->Title = L"Сохранить файл";
			// 
			// pictureMain
			// 
			this->pictureMain->Location = System::Drawing::Point(17, 95);
			this->pictureMain->Margin = System::Windows::Forms::Padding(4);
			this->pictureMain->Name = L"pictureMain";
			this->pictureMain->Size = System::Drawing::Size(911, 736);
			this->pictureMain->TabIndex = 0;
			this->pictureMain->TabStop = false;
			this->pictureMain->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::pictureMain_Paint);
			this->pictureMain->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureMain_MouseDown);
			this->pictureMain->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureMain_MouseMove);
			this->pictureMain->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureMain_MouseUp);
			// 
			// btnOpen
			// 
			this->btnOpen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnOpen->Location = System::Drawing::Point(17, 16);
			this->btnOpen->Margin = System::Windows::Forms::Padding(4);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(110, 35);
			this->btnOpen->TabIndex = 1;
			this->btnOpen->Text = L"Открыть";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSave->Location = System::Drawing::Point(135, 16);
			this->btnSave->Margin = System::Windows::Forms::Padding(4);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(133, 35);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"Сохранить";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MyForm::btnSave_Click);
			// 
			// btnSaveAs
			// 
			this->btnSaveAs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnSaveAs->Location = System::Drawing::Point(276, 16);
			this->btnSaveAs->Margin = System::Windows::Forms::Padding(4);
			this->btnSaveAs->Name = L"btnSaveAs";
			this->btnSaveAs->Size = System::Drawing::Size(164, 35);
			this->btnSaveAs->TabIndex = 2;
			this->btnSaveAs->Text = L"Сохранить как";
			this->btnSaveAs->UseVisualStyleBackColor = true;
			this->btnSaveAs->Click += gcnew System::EventHandler(this, &MyForm::btnSaveAs_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 20;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// panelCorner
			// 
			this->panelCorner->Controls->Add(this->lblCornerOptions);
			this->panelCorner->Controls->Add(this->btnRemoveCorner);
			this->panelCorner->Controls->Add(this->txtCornerY);
			this->panelCorner->Controls->Add(this->txtCornerX);
			this->panelCorner->Controls->Add(this->lblCornerY);
			this->panelCorner->Controls->Add(this->lblCornerX);
			this->panelCorner->Location = System::Drawing::Point(971, 212);
			this->panelCorner->Margin = System::Windows::Forms::Padding(4);
			this->panelCorner->Name = L"panelCorner";
			this->panelCorner->Size = System::Drawing::Size(267, 202);
			this->panelCorner->TabIndex = 4;
			this->panelCorner->Visible = false;
			// 
			// lblCornerOptions
			// 
			this->lblCornerOptions->AutoSize = true;
			this->lblCornerOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblCornerOptions->Location = System::Drawing::Point(9, 4);
			this->lblCornerOptions->Name = L"lblCornerOptions";
			this->lblCornerOptions->Size = System::Drawing::Size(193, 24);
			this->lblCornerOptions->TabIndex = 10;
			this->lblCornerOptions->Text = L"Настройки вершины";
			// 
			// btnRemoveCorner
			// 
			this->btnRemoveCorner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnRemoveCorner->Location = System::Drawing::Point(10, 137);
			this->btnRemoveCorner->Name = L"btnRemoveCorner";
			this->btnRemoveCorner->Size = System::Drawing::Size(204, 35);
			this->btnRemoveCorner->TabIndex = 9;
			this->btnRemoveCorner->Text = L"Удалить";
			this->btnRemoveCorner->UseVisualStyleBackColor = true;
			this->btnRemoveCorner->Click += gcnew System::EventHandler(this, &MyForm::btnRemoveCorner_Click);
			// 
			// txtCornerY
			// 
			this->txtCornerY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtCornerY->Location = System::Drawing::Point(56, 80);
			this->txtCornerY->Margin = System::Windows::Forms::Padding(4);
			this->txtCornerY->Name = L"txtCornerY";
			this->txtCornerY->Size = System::Drawing::Size(132, 28);
			this->txtCornerY->TabIndex = 3;
			this->txtCornerY->TextChanged += gcnew System::EventHandler(this, &MyForm::txtCornerY_TextChanged);
			// 
			// txtCornerX
			// 
			this->txtCornerX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtCornerX->Location = System::Drawing::Point(56, 32);
			this->txtCornerX->Margin = System::Windows::Forms::Padding(4);
			this->txtCornerX->Name = L"txtCornerX";
			this->txtCornerX->Size = System::Drawing::Size(132, 28);
			this->txtCornerX->TabIndex = 2;
			this->txtCornerX->TextChanged += gcnew System::EventHandler(this, &MyForm::txtCornerX_TextChanged);
			// 
			// lblCornerY
			// 
			this->lblCornerY->AutoSize = true;
			this->lblCornerY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblCornerY->Location = System::Drawing::Point(6, 83);
			this->lblCornerY->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblCornerY->Name = L"lblCornerY";
			this->lblCornerY->Size = System::Drawing::Size(43, 24);
			this->lblCornerY->TabIndex = 1;
			this->lblCornerY->Text = L"Y = ";
			// 
			// lblCornerX
			// 
			this->lblCornerX->AutoSize = true;
			this->lblCornerX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblCornerX->Location = System::Drawing::Point(6, 35);
			this->lblCornerX->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lblCornerX->Name = L"lblCornerX";
			this->lblCornerX->Size = System::Drawing::Size(45, 24);
			this->lblCornerX->TabIndex = 0;
			this->lblCornerX->Text = L"X = ";
			// 
			// panelMirror
			// 
			this->panelMirror->Controls->Add(this->lblMirrorOptions);
			this->panelMirror->Controls->Add(this->btnDivide);
			this->panelMirror->Controls->Add(this->lblMirrorRadius);
			this->panelMirror->Controls->Add(this->txtMirrorRadius);
			this->panelMirror->Controls->Add(this->rbtnMirrorConcave);
			this->panelMirror->Controls->Add(this->rbtnMirrorConvex);
			this->panelMirror->Controls->Add(this->lblMirrorType);
			this->panelMirror->Controls->Add(this->rbtnMirrorFlat);
			this->panelMirror->Location = System::Drawing::Point(971, 212);
			this->panelMirror->Name = L"panelMirror";
			this->panelMirror->Size = System::Drawing::Size(267, 367);
			this->panelMirror->TabIndex = 5;
			// 
			// lblMirrorOptions
			// 
			this->lblMirrorOptions->AutoSize = true;
			this->lblMirrorOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMirrorOptions->Location = System::Drawing::Point(9, 9);
			this->lblMirrorOptions->Name = L"lblMirrorOptions";
			this->lblMirrorOptions->Size = System::Drawing::Size(182, 24);
			this->lblMirrorOptions->TabIndex = 11;
			this->lblMirrorOptions->Text = L"Настройки зеркала";
			// 
			// btnDivide
			// 
			this->btnDivide->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btnDivide->Location = System::Drawing::Point(13, 234);
			this->btnDivide->Name = L"btnDivide";
			this->btnDivide->Size = System::Drawing::Size(204, 35);
			this->btnDivide->TabIndex = 8;
			this->btnDivide->Text = L"Разделить на два";
			this->btnDivide->UseVisualStyleBackColor = true;
			this->btnDivide->Click += gcnew System::EventHandler(this, &MyForm::btnDivide_Click);
			// 
			// lblMirrorRadius
			// 
			this->lblMirrorRadius->AutoSize = true;
			this->lblMirrorRadius->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMirrorRadius->Location = System::Drawing::Point(9, 158);
			this->lblMirrorRadius->Name = L"lblMirrorRadius";
			this->lblMirrorRadius->Size = System::Drawing::Size(171, 24);
			this->lblMirrorRadius->TabIndex = 5;
			this->lblMirrorRadius->Text = L"Радиус кривизны:";
			// 
			// txtMirrorRadius
			// 
			this->txtMirrorRadius->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtMirrorRadius->Location = System::Drawing::Point(13, 185);
			this->txtMirrorRadius->Name = L"txtMirrorRadius";
			this->txtMirrorRadius->Size = System::Drawing::Size(100, 28);
			this->txtMirrorRadius->TabIndex = 4;
			this->txtMirrorRadius->TextChanged += gcnew System::EventHandler(this, &MyForm::txtMirrorRadius_TextChanged);
			// 
			// rbtnMirrorConcave
			// 
			this->rbtnMirrorConcave->AutoSize = true;
			this->rbtnMirrorConcave->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbtnMirrorConcave->Location = System::Drawing::Point(12, 111);
			this->rbtnMirrorConcave->Name = L"rbtnMirrorConcave";
			this->rbtnMirrorConcave->Size = System::Drawing::Size(115, 28);
			this->rbtnMirrorConcave->TabIndex = 3;
			this->rbtnMirrorConcave->TabStop = true;
			this->rbtnMirrorConcave->Text = L"Вогнутое";
			this->rbtnMirrorConcave->UseVisualStyleBackColor = true;
			this->rbtnMirrorConcave->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtnMirrorConcave_CheckedChanged);
			// 
			// rbtnMirrorConvex
			// 
			this->rbtnMirrorConvex->AutoSize = true;
			this->rbtnMirrorConvex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbtnMirrorConvex->Location = System::Drawing::Point(12, 84);
			this->rbtnMirrorConvex->Name = L"rbtnMirrorConvex";
			this->rbtnMirrorConvex->Size = System::Drawing::Size(117, 28);
			this->rbtnMirrorConvex->TabIndex = 2;
			this->rbtnMirrorConvex->TabStop = true;
			this->rbtnMirrorConvex->Text = L"Выпуклое";
			this->rbtnMirrorConvex->UseVisualStyleBackColor = true;
			this->rbtnMirrorConvex->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtnMirrorConvex_CheckedChanged);
			// 
			// lblMirrorType
			// 
			this->lblMirrorType->AutoSize = true;
			this->lblMirrorType->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblMirrorType->Location = System::Drawing::Point(9, 33);
			this->lblMirrorType->Name = L"lblMirrorType";
			this->lblMirrorType->Size = System::Drawing::Size(125, 24);
			this->lblMirrorType->TabIndex = 1;
			this->lblMirrorType->Text = L"Тип зеркала:";
			// 
			// rbtnMirrorFlat
			// 
			this->rbtnMirrorFlat->AutoSize = true;
			this->rbtnMirrorFlat->Checked = true;
			this->rbtnMirrorFlat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbtnMirrorFlat->Location = System::Drawing::Point(12, 57);
			this->rbtnMirrorFlat->Name = L"rbtnMirrorFlat";
			this->rbtnMirrorFlat->Size = System::Drawing::Size(106, 28);
			this->rbtnMirrorFlat->TabIndex = 0;
			this->rbtnMirrorFlat->TabStop = true;
			this->rbtnMirrorFlat->Text = L"Плоское";
			this->rbtnMirrorFlat->UseVisualStyleBackColor = true;
			this->rbtnMirrorFlat->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtnMirrorFlat_CheckedChanged);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->rbtnModeRayCasting);
			this->panel1->Controls->Add(this->rbtnModeRoomEditing);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(971, 38);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(267, 169);
			this->panel1->TabIndex = 6;
			// 
			// rbtnModeRayCasting
			// 
			this->rbtnModeRayCasting->AutoSize = true;
			this->rbtnModeRayCasting->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->rbtnModeRayCasting->Location = System::Drawing::Point(13, 102);
			this->rbtnModeRayCasting->Name = L"rbtnModeRayCasting";
			this->rbtnModeRayCasting->Size = System::Drawing::Size(182, 52);
			this->rbtnModeRayCasting->TabIndex = 2;
			this->rbtnModeRayCasting->Text = L"Редактирование\r\nлуча";
			this->rbtnModeRayCasting->UseVisualStyleBackColor = true;
			this->rbtnModeRayCasting->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtnModeRayCasting_CheckedChanged);
			// 
			// rbtnModeRoomEditing
			// 
			this->rbtnModeRoomEditing->AutoSize = true;
			this->rbtnModeRoomEditing->Checked = true;
			this->rbtnModeRoomEditing->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->rbtnModeRoomEditing->Location = System::Drawing::Point(13, 41);
			this->rbtnModeRoomEditing->Name = L"rbtnModeRoomEditing";
			this->rbtnModeRoomEditing->Size = System::Drawing::Size(182, 52);
			this->rbtnModeRoomEditing->TabIndex = 1;
			this->rbtnModeRoomEditing->TabStop = true;
			this->rbtnModeRoomEditing->Text = L"Редактирование\r\nкомнаты";
			this->rbtnModeRoomEditing->UseVisualStyleBackColor = true;
			this->rbtnModeRoomEditing->CheckedChanged += gcnew System::EventHandler(this, &MyForm::rbtnModeRoomEditing_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(147, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Режим работы:";
			// 
			// panelRay
			// 
			this->panelRay->Controls->Add(this->txtReflectionsCount);
			this->panelRay->Controls->Add(this->lblReflectionsCount);
			this->panelRay->Controls->Add(this->lblRayOptions);
			this->panelRay->Controls->Add(this->txtAngle);
			this->panelRay->Controls->Add(this->lblAngle);
			this->panelRay->Location = System::Drawing::Point(971, 213);
			this->panelRay->Name = L"panelRay";
			this->panelRay->Size = System::Drawing::Size(267, 147);
			this->panelRay->TabIndex = 7;
			// 
			// txtReflectionsCount
			// 
			this->txtReflectionsCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->txtReflectionsCount->Location = System::Drawing::Point(13, 111);
			this->txtReflectionsCount->Name = L"txtReflectionsCount";
			this->txtReflectionsCount->Size = System::Drawing::Size(100, 28);
			this->txtReflectionsCount->TabIndex = 14;
			this->txtReflectionsCount->TextChanged += gcnew System::EventHandler(this, &MyForm::txtReflectionsCount_TextChanged);
			// 
			// lblReflectionsCount
			// 
			this->lblReflectionsCount->AutoSize = true;
			this->lblReflectionsCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->lblReflectionsCount->Location = System::Drawing::Point(9, 84);
			this->lblReflectionsCount->Name = L"lblReflectionsCount";
			this->lblReflectionsCount->Size = System::Drawing::Size(227, 24);
			this->lblReflectionsCount->TabIndex = 13;
			this->lblReflectionsCount->Text = L"Количество отражений:";
			// 
			// lblRayOptions
			// 
			this->lblRayOptions->AutoSize = true;
			this->lblRayOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblRayOptions->Location = System::Drawing::Point(9, 11);
			this->lblRayOptions->Name = L"lblRayOptions";
			this->lblRayOptions->Size = System::Drawing::Size(150, 24);
			this->lblRayOptions->TabIndex = 12;
			this->lblRayOptions->Text = L"Настройки луча";
			// 
			// txtAngle
			// 
			this->txtAngle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txtAngle->Location = System::Drawing::Point(92, 38);
			this->txtAngle->Name = L"txtAngle";
			this->txtAngle->Size = System::Drawing::Size(100, 28);
			this->txtAngle->TabIndex = 1;
			this->txtAngle->TextChanged += gcnew System::EventHandler(this, &MyForm::txtAngle_TextChanged);
			// 
			// lblAngle
			// 
			this->lblAngle->AutoSize = true;
			this->lblAngle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblAngle->Location = System::Drawing::Point(9, 41);
			this->lblAngle->Name = L"lblAngle";
			this->lblAngle->Size = System::Drawing::Size(73, 24);
			this->lblAngle->TabIndex = 0;
			this->lblAngle->Text = L"Угол = ";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1251, 846);
			this->Controls->Add(this->panelRay);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panelMirror);
			this->Controls->Add(this->panelCorner);
			this->Controls->Add(this->btnSaveAs);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnOpen);
			this->Controls->Add(this->pictureMain);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"Тест";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureMain))->EndInit();
			this->panelCorner->ResumeLayout(false);
			this->panelCorner->PerformLayout();
			this->panelMirror->ResumeLayout(false);
			this->panelMirror->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panelRay->ResumeLayout(false);
			this->panelRay->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	void setEnable(System::Windows::Forms::Control^ item, bool enable) {
		item->Visible = enable;
		item->Enabled = enable;
	}

	void clearMatrix(System::Windows::Forms::DataGridView^ grd) {
		grd->Columns->Clear();
		grd->Rows->Clear();
	}

	void clearText(System::Windows::Forms::TextBox^ txt) {
		txt->Text = "";
	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Room::getInstance()->setWidth(pictureMain->Width);
		Room::getInstance()->setHeight(pictureMain->Height);

		fileName = "Безымянный.txt";
		updateFormText();

		timer1->Start();
	}

	int cnt = 0;

	protected: System::Void pictureMain_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
	}
	
	private: System::Void pictureMain_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		FocusController::getInstance()->onMouseDown(e);
		mirrorDataOutput();
	}

	void repaint() {
		Bitmap^ buf = gcnew Bitmap(pictureMain->Width, pictureMain->Height);

		Graphics^ g = Graphics::FromImage(buf);
		g->FillRectangle(gcnew SolidBrush(Color::White), 0, 0, pictureMain->Width, pictureMain->Height);
		g->DrawRectangle(gcnew Pen(Color::Black), 0, 0, pictureMain->Width - 1, pictureMain->Height - 1);

		Room::getInstance()->draw(g);

		Ray::getInstance()->draw(g);

		pictureMain->Image = buf;
	}

	void updateFormText() {
		this->Text = "Эксперимент в зеркальной комнате - ";
		this->Text += fileName;
	}

	private: System::Void pictureMain_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		FocusController::getInstance()->onMouseUp(e);
	}

	private: System::Void pictureMain_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		FocusController::getInstance()->onMouseMove(e);
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		cornerOptionsUpdate();
		mirrorOptionsUpdate();
		rayOptionsUpdate();
		Room::getInstance()->update();
		repaint();
	}

	private: void setCornerOptionsVisible(bool visible) {
		setEnable(panelCorner, visible);
		setEnable(lblCornerX, visible);
		setEnable(lblCornerY, visible);
		setEnable(txtCornerX, visible);
		setEnable(txtCornerY, visible);
	}

	private: void setMirrorOptionsVisible(bool visible) {
		setEnable(panelMirror, visible);
		setEnable(lblMirrorType, visible);
		setEnable(lblMirrorRadius, visible);
		setEnable(rbtnMirrorFlat, visible);
		setEnable(rbtnMirrorConvex, visible);
		setEnable(rbtnMirrorConcave, visible);
	}

	private: void setRayOptionsVisible(bool visible) {
		setEnable(panelRay, visible);
		setEnable(lblAngle, visible);
		setEnable(txtAngle, visible);
		setEnable(lblReflectionsCount, visible);
		setEnable(txtReflectionsCount, visible);
	}

	private: void mirrorDataOutput() {
		if (Mirror^ mirror = FocusController::getInstance()->getFocusedMirror()) {
			rbtnMirrorFlat->Checked = (mirror->getMirrorType() == Mirror::MirrorType::Flat);
			rbtnMirrorConvex->Checked = (mirror->getMirrorType() == Mirror::MirrorType::Convex);
			rbtnMirrorConcave->Checked = (mirror->getMirrorType() == Mirror::MirrorType::Concave);

			txtMirrorRadius->Text = gcnew System::String(
				std::to_string(int(mirror->getRadius() + Vector::EPS)).c_str());
		}
	}

	private: void rayDataOutput() {
		if (ModeController::getInstance()->getMode() == ModeController::ModeType::RayCasting) {
			txtAngle->Text = gcnew System::String(
				std::to_string(int(Ray::getInstance()->getAngle() + Vector::EPS)).c_str());
			txtReflectionsCount->Text = gcnew System::String(
				std::to_string(Ray::getInstance()->getIterationsCount() - 1).c_str());
		}
	}

	private: void cornerOptionsUpdate() {
		if (Corner^ corner = FocusController::getInstance()->getFocusedCorner()) {
			setCornerOptionsVisible(true);
			if (FocusController::getInstance()->isMouseDown()) {
				txtCornerX->Text = gcnew System::String(
					std::to_string(int(corner->getPosition()->getX() + Vector::EPS)).c_str());
				txtCornerY->Text = gcnew System::String(
					std::to_string(int(corner->getPosition()->getY() + Vector::EPS)).c_str());
			}
		}
		else {
			setCornerOptionsVisible(false);
		}
	}

	private: System::Void txtCornerX_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		if (Corner^ corner = FocusController::getInstance()->getFocusedCorner()) {
			int x;
			bool result = Int32::TryParse(txtCornerX->Text, x);
		
			if (!result) {
				errorProvider1->SetError(txtCornerX, "Ошибка ввода");
				return;
			}

			x = std::max(double(x), corner->getRadius());
			x = std::min(double(x), pictureMain->Width - corner->getRadius());

			corner->getPosition()->setX(x);
		}
	}

	private: System::Void txtCornerY_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		if (Corner^ corner = FocusController::getInstance()->getFocusedCorner()) {
			int y;
			bool result = Int32::TryParse(txtCornerY->Text, y);

			if (!result) {
				errorProvider1->SetError(txtCornerY, "Ошибка ввода");
				return;
			}

			y = std::max(double(y), corner->getRadius());
			y = std::min(double(y), pictureMain->Height - corner->getRadius());

			corner->getPosition()->setY(y);
		}
	}

	private: void mirrorOptionsUpdate() {
		if (Mirror^ mirror = FocusController::getInstance()->getFocusedMirror()) {
			setMirrorOptionsVisible(true);
		}
		else {
			setMirrorOptionsVisible(false);
		}
	}

	private: void rayOptionsUpdate() {
		if (ModeController::getInstance()->getMode() == ModeController::ModeType::RayCasting) {
			setRayOptionsVisible(true);
		}
		else {
			setRayOptionsVisible(false);
		}
	}

	void updateMirrorType() {
		if (Mirror^ mirror = FocusController::getInstance()->getFocusedMirror()) {
			if (rbtnMirrorFlat->Checked) {
				mirror->setMirrorType(Mirror::MirrorType::Flat);
			}
			else if (rbtnMirrorConvex->Checked) {
				mirror->setMirrorType(Mirror::MirrorType::Convex);
			} 
			else if (rbtnMirrorConcave->Checked) {
				mirror->setMirrorType(Mirror::MirrorType::Concave);
			}
		}
	}

	private: System::Void btnDivide_Click(System::Object^ sender, System::EventArgs^ e) {
		Room::getInstance()->divide();
	}

	private: System::Void btnRemoveCorner_Click(System::Object^ sender, System::EventArgs^ e) {
		Room::getInstance()->removeFocusedCorner();
	}

	private: System::Void txtMirrorRadius_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		if (Mirror^ mirror = FocusController::getInstance()->getFocusedMirror()) {
			int radius;
			bool result = Int32::TryParse(txtMirrorRadius->Text, radius);

			if (!result) {
				errorProvider1->SetError(txtMirrorRadius, "Ошибка ввода");
				return;
			}

			mirror->setRadius(radius);
		}
	}

	private: System::Void rbtnMirrorFlat_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		updateMirrorType();
		mirrorDataOutput();
	}

	private: System::Void rbtnMirrorConvex_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		updateMirrorType();
		mirrorDataOutput();
	}
	
	private: System::Void rbtnMirrorConcave_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		updateMirrorType();
		mirrorDataOutput();
	}

	private: System::Void rbtnModeRoomEditing_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ModeController::getInstance()->setMode(ModeController::ModeType::RoomEditing);
	}

	private: System::Void rbtnModeRayCasting_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ModeController::getInstance()->setMode(ModeController::ModeType::RayCasting);
		rayDataOutput();
	}

	private: System::Void txtAngle_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		int angle;
		bool result = Int32::TryParse(txtAngle->Text, angle);

		if (!result) {
			errorProvider1->SetError(txtAngle, "Ошибка ввода");
			return;
		}

		Ray::getInstance()->setAngle(angle);
	}

	private: System::Void txtReflectionsCount_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorProvider1->Clear();
		int count;
		bool result = Int32::TryParse(txtReflectionsCount->Text, count);

		if (!result || count < 0) {
			errorProvider1->SetError(txtReflectionsCount, "Ошибка ввода");
			return;
		}

		Ray::getInstance()->setIterationsCount(count + 1);
	}

	String^ fileName;
	bool fileOpened = false;

	private: System::Void btnSaveAs_Click(System::Object^ sender, System::EventArgs^ e) {
		SaveExperimentAs();
	}

	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!fileOpened)
			SaveExperimentAs();
		else {
			SaveExperiment(gcnew System::IO::FileStream(fileName, System::IO::FileMode::Open));
		}
	}

	private: System::Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e) {
		System::IO::Stream^ stream;
		if (this->openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((stream = openFileDialog->OpenFile()) != nullptr) {
				fileName = openFileDialog->FileName;
				fileOpened = true;
				updateFormText();
				System::IO::StreamReader^ sw = gcnew System::IO::StreamReader(stream, System::Text::Encoding::GetEncoding(1251));
				System::String^ s = "";
				int n = Int32::Parse(sw->ReadLine());
				auto corners = Room::getInstance()->getCorners();
				corners->Clear();
				for (int i = 0; i < n; i++) {
					auto p = sw->ReadLine()->Split(' ');
					corners->Add(gcnew Corner(gcnew Vector(Double::Parse(p[0]), Double::Parse(p[1]))));
				}

				auto mirrors = Room::getInstance()->getMirrors();
				mirrors->Clear();
				for (int i = 0; i < n; i++) {
					auto p = sw->ReadLine()->Split(' ');
					mirrors->Add(gcnew Mirror(corners[i], corners[(i + 1) % n]));
					mirrors[i]->setRadius(Double::Parse(p[1]));
					if (p[0] == "Flat") {
						mirrors[i]->setMirrorType(Mirror::MirrorType::Flat);
					}
					else if (p[0] == "Convex") {
						mirrors[i]->setMirrorType(Mirror::MirrorType::Convex);
					}
					else if (p[0] == "Concave") {
						mirrors[i]->setMirrorType(Mirror::MirrorType::Concave);
					}
				}

				auto p = sw->ReadLine()->Split(' ');
				Ray::getInstance()->setStart(gcnew Vector(Double::Parse(p[0]), Double::Parse(p[1])));
				Ray::getInstance()->setAngle(Double::Parse(p[2]));
				Ray::getInstance()->setIterationsCount(Double::Parse(p[3]));

				sw->Close();
				ModeController::getInstance()->setMode(ModeController::ModeType::RayCasting);
				rbtnModeRayCasting->Checked = true;
			}
		}
	}

	void SaveExperimentAs() {
		System::IO::Stream^ stream;
		if (this->saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			if ((stream = saveFileDialog->OpenFile()) != nullptr) {
				SaveExperiment(stream);
				fileName = saveFileDialog->FileName;
				fileOpened = true;
				updateFormText();
			}
				
	}
	
	void SaveExperiment(System::IO::Stream^ stream) {
		System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(stream, System::Text::Encoding::GetEncoding(1251));

		auto corners = Room::getInstance()->getCorners();

		int n = corners->Count;
		sw->WriteLine(n);

		for (int i = 0; i < n; i++) {
			sw->WriteLine("{0} {1}", corners[i]->getPosition()->getX(), corners[i]->getPosition()->getY());
		}

		auto mirrors = Room::getInstance()->getMirrors();
		for (int i = 0; i < n; i++) {
			String^ str = "";
			if (mirrors[i]->getMirrorType() == Mirror::MirrorType::Flat)
				str = "Flat";
			else if (mirrors[i]->getMirrorType() == Mirror::MirrorType::Convex)
				str = "Convex";
			else if (mirrors[i]->getMirrorType() == Mirror::MirrorType::Concave)
				str = "Concave";
			str += " {0}";
			sw->WriteLine(str, mirrors[i]->getRadius());
		}

		sw->WriteLine("{0} {1} {2} {3}",
			Ray::getInstance()->getStart()->getX(),
			Ray::getInstance()->getStart()->getY(),
			Ray::getInstance()->getAngle(), 
			Ray::getInstance()->getIterationsCount());

		sw->Close();
	}


};
}
