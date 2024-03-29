/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

struct ManagementSystem
{

  string NameOfpatient, phoneNumber, addressOfpatient;
  int IDpatient;
  double Invoice;
  ManagementSystem *Next;

};

ManagementSystem *head;

void
Show_patient_record ()
{
  ManagementSystem *temp = head;

  if (temp == NULL)
	{
	  cout << " The list is empty\n";
	}
  cout << "\n> Show all records : \n";
  cout << "\n>------------------------------------------------------- \n";
  while (temp != NULL)
	{
	  cout << "\n * Name of patient  : " << " " << temp->NameOfpatient;
	  cout << "\n * ID of patient  : " << " " << temp->IDpatient;
	  cout << "\n * phone Number of patient  : " << " " << temp->phoneNumber;
	  cout << "\n * address of patient  : " << " " << temp->addressOfpatient;
	  cout << "\n * The total of Invoice  : " << " " << temp->Invoice;

	  temp = temp->Next;
	  cout << "\n>------------------------------------------------------- \n";
	}
}

bool CheckRecord (int ID);

void
Insert_patient_record (ManagementSystem ** head, string Name, int ID,
					   string phoneNum, string address, double Invo)
{

  ManagementSystem *record = new ManagementSystem ();
  record->NameOfpatient = Name;

  while (CheckRecord (ID))
	{
	  cout << "Patient with ID is already exist enter another ID ";
	  cin >> ID;

	}

  record->IDpatient = ID;
  record->phoneNumber = phoneNum;
  record->addressOfpatient = address;
  record->Invoice = Invo;
  record->Next = NULL;

  ManagementSystem *helpptr = new ManagementSystem ();
  helpptr = *head;


  if (*head == NULL)
	{
	  *head = record;
	  return;
	}
  while (helpptr->Next != NULL)
	{
	  helpptr = helpptr->Next;
	}
  helpptr->Next = record;

}




void
patient_record ()
{
  string NameOfpatient, phoneNumber, addressOfpatient;
  int IDpatient;
  double Invoice;
  int insertNum;
  head = NULL;
  cout << "> How many record do you want to insert: ";
  cin >> insertNum;

  for (int i = 0; i < insertNum; i++)
	{

	  cout << "\n*** The patient record *** " << "\n\n";
	  cout << ">Name of patient  : " << "\n";
	  cin >> NameOfpatient;
	  cout << ">ID of patient  : " << "\n";
	  cin >> IDpatient;
	  cout << ">Phone number of the patient : " << "\n";
	  cin >> phoneNumber;
	  cout << ">Address of the patient : " << "\n";
	  cin >> addressOfpatient;
	  cout << ">The total of Invoice : " << "\n";
	  cin >> Invoice;


	  Insert_patient_record (&head, NameOfpatient, IDpatient, phoneNumber,
							 addressOfpatient, Invoice);

	  cout <<
		" The patient record was successfully inserted into the list.\n";
	  cout <<
		"\n\n>------------------------------------------------------- \n\n";
	}

}


bool
CheckRecord (int ID)
{
  ManagementSystem *help = head;;
  if (help == NULL)
	return false;
  else
	{
	  ManagementSystem *temp = head;
	  while (temp != NULL)
		{
		  if (temp->IDpatient == ID)
			return true;
		  temp = temp->Next;
		}
	  return false;
	}
}






void
DeleteByID (int ID)
{

  ManagementSystem *current = head;
  ManagementSystem *prev = head;


  if (current->IDpatient == ID)
	{
	  head = current->Next;
	  free (current);
	  cout << "Patient with ID [ " << current->
		IDpatient << " ] is removed from the List.\n";

	  cout <<
		"-------------------------------------------------------------\n\n";
	}
  else
	{
	  while (current->IDpatient != ID)
		{
		  prev = current;
		  current = current->Next;
		}

	  prev->Next = current->Next;
	  free (current);
	  cout << "Patient with ID [ " << current->
		IDpatient << " ] is removed from the List.\n";
	  cout <<
		"-------------------------------------------------------------\n\n";
	}


}

void
SearchRecordByID (int ID)
{

  ManagementSystem *search = head;
  ManagementSystem *prev = head;


  if (search->IDpatient == ID)
	{

	  cout << "Displying Patient " << search->IDpatient << " Record : \n\n";

	  cout << "Name: " << search->NameOfpatient << "\n";
	  cout << "ID: " << search->IDpatient << "\n";
	  cout << "Phone Number: " << search->phoneNumber << "\n";
	  cout << "Address: " << search->addressOfpatient << "\n";
	  cout << "The total of Invoice: " << " " << search->Invoice << "\n";
	  cout << "\n>------------------------------------------------------- \n";
	}
  else
	{
	  while (search->IDpatient != ID)
		{
		  cout << "\n--There is no Patient with this ID.-- \n";
		  prev = search;
		  search = search->Next;

		}

	  cout << "Displying Patient " << search->IDpatient << " Record : \n\n";

	  cout << "Name: " << search->NameOfpatient << "\n";
	  cout << "ID: " << search->IDpatient << "\n";
	  cout << "Phone Number: " << search->phoneNumber << "\n";
	  cout << "Address: " << search->addressOfpatient << "\n";
	  cout << "The total of Invoice: " << " " << search->Invoice << "\n";
	  cout << "\n>------------------------------------------------------- \n";


	}

}

void
updateInvoice (ManagementSystem * head)
{
  ManagementSystem *update = head;
  cout <<
	"\n\n * Hint : there is a  VAT (15%) only on invoices more than 100 SR. \n\n";

  while (update != NULL)
	{
	  if (update->Invoice > 100)
		{
		  update->Invoice = (update->Invoice * 0.15) + update->Invoice;
		}
	  update = update->Next;
	}
}

void
deleteInvoice (ManagementSystem * head)
{
  ManagementSystem *del = head;
  cout <<
	"\n\n * Hint : Your Invoice will be deleted if it is less than 10 SR.\n\n";
  while (del != NULL)
	{
	  if (del->Invoice < 10)
		{
		  cout << "\n\n * Invoice of Patient [ " << del->
			Invoice << " ] is removed from the List.\n";
		  del->Invoice = 0;
		}
	  del = del->Next;
	}


}

void
updateRecord ()
{
  ManagementSystem *update = head;
  string data;
  int id;
  cout << "\n Update patient Record? Y/N  : \n";
  // cout<<"\n Enter current patient ID  : \n";
  cin >> data;
  cout << "Enter patient ID: ";
  cin >> id;

  while (update->Next != NULL)
	{

	  if ("Y" == data && update->IDpatient == id)
		{
		  int new_ID;
		  cout << "\n Enter your new patient ID :\n";
		  cin >> new_ID;
		  update->IDpatient = new_ID;
		}
	  else
		{
		  update = update->Next;
		}


	}

  //Show_patient_record(); 

}






int
main ()
{
  int id, value;


  do
	{
	  cout << endl;

	  cout << "|------------  \t     patient System \t    ------------|" <<
		endl;

	  cout << "|\t1. Insert all patient records  \t  \t  \t|" << endl;
	  cout << "|\t2. Delete patientb s record    \t \t \t|" << endl;
	  cout << "|\t3. Update patientb s record   \t \t \t|" << endl;
	  cout << "|\t4. Show patientb s record   \t \t \t|" << endl;
	  cout << "|\t5. Search patientb s by ID \t \t \t|" << endl;
	  cout << "|\t6. Update Invoice   \t \t|" << endl;
	  cout << "|\t7. Logout \t\t\t\t \t \t|" << endl;
	  cout <<
		"|---------------------------------------------------------------|" <<
		endl;

	  cout << "\n> Please enter opeation : ";
	  cin >> value;
	  cout << endl;
	  switch (value)
		{

		case 1:

		  patient_record ();
		  break;

		case 2:
		  deleteInvoice (head);
		  break;

		case 3:
		  updateInvoice (head);

		  break;

		case 4:
		  Show_patient_record ();

		  break;

		case 5:				// Print number of inner nodes of tree
		  cout << "Enter patient ID to search for patient Record: \n";
		  cin >> id;
		  SearchRecordByID (id);
		  break;
		case 6:
		  updateInvoice (head);
		  break;

		}
	}
  while (value < 7);






  return 0;
}
