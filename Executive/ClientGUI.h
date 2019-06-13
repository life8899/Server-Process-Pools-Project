#pragma once
#ifndef CLIENTGUI_H
#define CLIENTGUI_H

#include <iostream>

using std::cout;
using std::endl;



using System::Object;
using System::Windows::Controls::Button;
using System::Windows::Controls::ColumnDefinition;
using System::Windows::Controls::Grid;
using System::Windows::Controls::RowDefinition;
using System::Windows::RoutedEventArgs;
using System::Windows::RoutedEventHandler;

namespace testingWindow
{

	ref class TestingWindow : System::Windows::Window
	{

	public:

		void testButtonClicked(Object^ sender, RoutedEventArgs^ args);

		TestingWindow()
		{

			// set some basic properties of the window
			this->Title = "Testing GUI";
			this->Width = 450;
			this->MinWidth = 450;
			this->Height = 320;
			this->MinHeight = 320;
			this->Name = "MainWindow";

			// create a grid layout
			mainGrid = gcnew Grid();

			ColumnDefinition^ coldef1 = gcnew ColumnDefinition();
			ColumnDefinition^ coldef2 = gcnew ColumnDefinition();
			ColumnDefinition^ coldef3 = gcnew ColumnDefinition();
			ColumnDefinition^ coldef4 = gcnew ColumnDefinition();
			mainGrid->ColumnDefinitions->Add(coldef1);
			mainGrid->ColumnDefinitions->Add(coldef2);
			mainGrid->ColumnDefinitions->Add(coldef3);

			RowDefinition^ rowdef1 = gcnew RowDefinition();
			RowDefinition^ rowdef2 = gcnew RowDefinition();
			RowDefinition^ rowdef3 = gcnew RowDefinition();
			RowDefinition^ rowdef4 = gcnew RowDefinition();
			mainGrid->RowDefinitions->Add(rowdef1);
			mainGrid->RowDefinitions->Add(rowdef2);
			mainGrid->RowDefinitions->Add(rowdef3);

			// set the content of our window to this grid layout
			this->Content = mainGrid;

			// create a new button and add it to our grid layout
			testButton = gcnew Button();
			testButton->Content = "Push Me";
			mainGrid->SetRow(testButton, 1);
			mainGrid->SetColumn(testButton, 1);
			mainGrid->Children->Add(testButton);

			// add the eventhandler for this button
			testButton->Click += gcnew RoutedEventHandler(this, &TestingWindow::testButtonClicked);

		}

	private:

		System::Windows::Controls::Button^ testButton;
		System::Windows::Controls::Grid^ mainGrid;

	};

	void TestingWindow::testButtonClicked(Object^ sender, RoutedEventArgs^ args)
	{
		cout << "push me" << endl;
	}
};

#endif 