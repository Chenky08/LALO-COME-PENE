#pragma once
#include "Juego.h"
#include <iostream>
namespace tanques2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			srand(time(0));
			juego = new Juego(10,10);
			imgTanque = gcnew Bitmap("tanque.png");
			imgEnemigo = gcnew Bitmap("enemigo.png");
			imgLadrillo = gcnew Bitmap("ladrillo.png");
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
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
		Juego* juego;
		Bitmap^ imgTanque;
		Bitmap^ imgEnemigo;
		Bitmap^ imgLadrillo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(939, 517);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyUp);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this -> CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		juego->iniciar(buffer->Graphics, imgTanque,imgEnemigo,imgLadrillo);

		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::Up: juego->getTanque()->setTecla(Arriba); break;
		case Keys::Down: juego->getTanque()->setTecla(Abajo); break;
		case Keys::Left: juego->getTanque()->setTecla(Izquierda); break;
		case Keys::Right: juego->getTanque()->setTecla(Derecha); break;
		case Keys::Space: juego->getTanque()->disparar(); break;
		}
	}
	private: System::Void MyForm_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		juego->getTanque()->setTecla(Ninguno);
	}
	};
}
