#pragma once
#include "Juego.h"
namespace formulario1 {

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
			juego = new Juego();
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

	protected:



	private: System::Windows::Forms::TextBox^ txtnumero;

	private: System::Windows::Forms::Button^ button1;


	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ lblVidas;
	private: System::Windows::Forms::Label^ lblPuntos;

	protected:

	private:
	
		Juego* juego;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->txtnumero = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblVidas = (gcnew System::Windows::Forms::Label());
			this->lblPuntos = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtnumero
			// 
			this->txtnumero->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtnumero->Location = System::Drawing::Point(358, 439);
			this->txtnumero->Name = L"txtnumero";
			this->txtnumero->Size = System::Drawing::Size(317, 62);
			this->txtnumero->TabIndex = 0;
			this->txtnumero->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(358, 517);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(317, 54);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Aceptar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// lblVidas
			// 
			this->lblVidas->AutoSize = true;
			this->lblVidas->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblVidas->Location = System::Drawing::Point(902, 11);
			this->lblVidas->Name = L"lblVidas";
			this->lblVidas->Size = System::Drawing::Size(102, 25);
			this->lblVidas->TabIndex = 2;
			this->lblVidas->Text = L"Vidas: 10";
			// 
			// lblPuntos
			// 
			this->lblPuntos->AutoSize = true;
			this->lblPuntos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntos->Location = System::Drawing::Point(901, 549);
			this->lblPuntos->Name = L"lblPuntos";
			this->lblPuntos->Size = System::Drawing::Size(103, 25);
			this->lblPuntos->TabIndex = 3;
			this->lblPuntos->Text = L"Puntos: 0";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1015, 583);
			this->Controls->Add(this->lblPuntos);
			this->Controls->Add(this->lblVidas);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtnumero);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnaceptar_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ g = this->CreateGraphics();
		BufferedGraphicsContext^ espacio = BufferedGraphicsManager::Current;
		BufferedGraphics^ buffer = espacio->Allocate(g, ClientRectangle);
		buffer->Graphics->Clear(Color::White);
		juego->iniciar(buffer->Graphics);
		lblPuntos->Text = "Puntos: " + juego->getPuntos();
		lblVidas->Text = "Vidas: " + juego->getVidas();
		buffer->Render(g);
		delete buffer, espacio, g;
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		int numero_entrada = Convert::ToInt32(txtnumero->Text);
		juego->obtenerRespuesta(numero_entrada);
		txtnumero->Text = "";
	}
};
}
