#pragma once


namespace Task01 {
#include <math.h>
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Form1
	///
	/// Внимание! При изменении имени этого класса необходимо также изменить
	///          свойство имени файла ресурсов ("Resource File Name") для средства компиляции управляемого ресурса,
	///          связанного со всеми файлами с расширением .resx, от которых зависит данный класс. В противном случае,
	///          конструкторы не смогут правильно работать с локализованными
	///          ресурсами, сопоставленными данной форме.
	/// </summary>
	const double PI = 3.1415926535897932384626433832795;
	const double TPI = 2 * 3.1415926535897932384626433832795;
	double mod2pi(double x){
		double y = x;
		while (y >= PI) y = y - TPI;
		while (y < -PI) y = y + TPI;
		return y;		
	}


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			Xmin = 0; Xmax = 1; Ymin = 0; Ymax = 1;
		}
	//наши объявления:
    private:
		float *xx = new float(10);
		float *yy = new float(10);
      double Xmin, Xmax, Ymin, Ymax;//инициализация - в конструкторе
	private: System::Windows::Forms::ToolStripMenuItem^  plotToolStripMenuItem;

	float Y0, X0, X1, Y1,x0, y0, x1,y1,x11,y11;
	private: System::Windows::Forms::Button^  button1;

			 int nmodel = 0;
	

      void ToScreen(double X, double Y, int& xs, int& ys)
	  { xs = (X-Xmin)/(Xmax-Xmin)*panel1->Width;
	    ys = (Ymax - Y)/(Ymax-Ymin)*panel1->Height;
	  }
	  void ToWorld(double xs, double ys, double& X, double& Y)
	  {
		   X=Xmin+xs*(Xmax-Xmin)/panel1->Width;		   
		   Y=Ymax-ys*(Ymax-Ymin)/panel1->Height;
	  }

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  windowToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  clearToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::StatusStrip^  statusStrip1;
	private: System::Windows::Forms::Panel^  panel1;

	protected: 

	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->windowToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->plotToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(593, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->saveToolStripMenuItem,
					this->toolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->saveToolStripMenuItem->Text = L"Save...";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(104, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(107, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->windowToolStripMenuItem,
					this->clearToolStripMenuItem, this->plotToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// windowToolStripMenuItem
			// 
			this->windowToolStripMenuItem->Name = L"windowToolStripMenuItem";
			this->windowToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->windowToolStripMenuItem->Text = L"Window...";
			// 
			// clearToolStripMenuItem
			// 
			this->clearToolStripMenuItem->Name = L"clearToolStripMenuItem";
			this->clearToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->clearToolStripMenuItem->Text = L"Clear";
			// 
			// plotToolStripMenuItem
			// 
			this->plotToolStripMenuItem->Name = L"plotToolStripMenuItem";
			this->plotToolStripMenuItem->Size = System::Drawing::Size(127, 22);
			this->plotToolStripMenuItem->Text = L"Plot";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(116, 22);
			this->aboutToolStripMenuItem->Text = L"About...";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Location = System::Drawing::Point(0, 422);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(593, 22);
			this->statusStrip1->TabIndex = 1;
			this->statusStrip1->Text = L"statusStrip1";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(593, 398);
			this->panel1->TabIndex = 2;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::panel1_MouseClick);
			this->panel1->Resize += gcnew System::EventHandler(this, &Form1::panel1_Resize);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(359, 53);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(593, 444);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->statusStrip1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void exitToolStripMenuItem_Click(
				 System::Object^  sender, 
				 System::EventArgs^  e) 
	{ this->Close();
	}

			 



private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void Draw_line(float x1, float y1,float x2, float y2){
			 Graphics^ g = panel1->CreateGraphics();			 
			 Pen^ p = gcnew Pen(Color::Red);
			 int xs1, ys1;
			 int xs2, ys2;
			 ToScreen(x1, y1, xs1, ys1);
			 ToScreen(x2, y2, xs2, ys2);
			 g->DrawLine(p, xs1, ys1, xs2, ys2);			 
}		

private: System::Void DrawFrac(float xA, float yA, float xB, float yB, int n){		 
			 
			 float x, y, x1, y1, dx = xB - xA, dy = yB - yA;

			 if (n == 0)
			 {
				 Draw_line(xA, yA, xB, yB);
			 }
			 else {
				 x1 = xA;
				 y1 = yA;
				 for (int i = 1; i <= nmodel; i++)
				 {
					 x = x1;
					 y = y1;
					 x1 = xA + dx * xx[i] - dy * yy[i];
					 y1 = yA + dy * xx[i] + dx * yy[i];
					 DrawFrac(x, y, x1, y1, n - 1);
				 }

			 }

}

private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {	



			 }
		 

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		
			
			 xx[1] = 0;			yy[1] = 0;
			 xx[2] = 0.3;		yy[2] = 0.3;
			 xx[3] = 0.7;		yy[3] = -0.3;
			 xx[4] = 1;			yy[4] = 0;
			 //xx[1] = 0; yy[1] = 0;
			 //xx[2] = 0.47;  yy[2] = 0;
			 //xx[3] = 0.5; yy[3] = 0.47;
			 //xx[4] = 0.53; yy[4] = 0;
			 //xx[5] = 1; yy[5] = 0;
			 nmodel = 4;
			 int n, k, i;
			 float pi, theta, r, x, y, x1, y1, xC, yC, sizefactor, xmargin, phi;
			
			 nmodel++;
			 sizefactor = 0.9; // коэффициент масштабирования
			 xx[nmodel] = 1.0;
			 n = 2;
			 k = 4;


			 xC = Xmax / 2;
			 yC = Ymax / 2;
			 r = 0.9 * yC * sizefactor; 
			 pi = 3.14159;
			 theta = 2 * pi / k;
			 phi = -0.5 * theta;
			 x1 = xC + r * cos(phi);
			 y1 = yC + r * sin(phi);

			 for (i = 0; i < k; i++)
			 {

				 x = x1;
				 y = y1;
				 phi += theta;
				 x1 = xC + r * cos(phi);
				 y1 = yC + r * sin(phi);
				 DrawFrac(x, y, x1, y1, n);

			 }
}
private: System::Void panel1_Resize(System::Object^  sender, System::EventArgs^  e) {		
			
}
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 Invalidate();
}
};
}



