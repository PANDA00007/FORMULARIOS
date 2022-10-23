#pragma once
#include "VecFiguras.h"

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			g = this->CreateGraphics();
			arrf = new ArregloFiguras();
			//bucle infinito para que llame constantemente a las figuras
			timer1->Enabled = true;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ g;
		ArregloFiguras* arrf;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(569, 465);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::C)
			arrf->agregarFigura(g, 'C');
		if (e->KeyCode == Keys::D)
			arrf->agregarFigura(g, 'D');
		if (e->KeyCode == Keys::E)
			arrf->agregarFigura(g, 'E');
		if (e->KeyCode == Keys::R)
			arrf->agregarFigura(g, 'R');
		if (e->KeyCode == Keys::T)
			arrf->agregarFigura(g, 'T');
	}
	
	private: System::Void MyForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		g->Clear(Color::White);
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		arrf->mostrar(g);
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// Al compilar, es lo primero que carga
		g->Clear(Color::White);
	}
	};
}
