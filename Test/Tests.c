#include "Tests.h"
#include <stdbool.h>
#include <stdio.h>

/* Test Code to test the Sign Up */
static struct User_Input_Type User1 =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Abdelrahman",
	26,
	7,
	12,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"abdelrahmanA",
			"abdelrahmanA"
		},
	"abdelrahmanA"
	}
};
static struct User_Input_Type User2 =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Abdelrahman",
	26,
	8,
	11,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"abdelrahmanA",
			"abdelrahmanA"
		},
	"abdelrahmanA"
	}
};
static struct User_Input_Type User3 =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Abdelrahman",
	26,
	3,
	2,
	1998,
	Male,
	Masters_Student
	},
	{
		{
			"abdelrahmanA",
			"abdelrahmanB"
		},
	"abdelrahmanB"
	}
};
static struct User_Input_Type Test1_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Ahmed",
	25,
	23,
	10,
	1999,
	Male,
	PHD_Holder
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
}; 

/* Test Code to test the Sign Up */
static struct User_Input_Type Test2_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Rania",
	54,
	31,
	12,
	1970,
	Female,
	PHD_Holder
	},
	{
		{
			"EdgesAcademy2024",
			"Edges_123_"
		},
	"Edges_123_$$"
	}
};
static struct User_Input_Type Test3_User =
{
	{
	-1, // this is to indecate user hasn't assigned ID 
	"Ahmed",
	25,
	23,
	10,
	1999,
	Male,
	PHD_Student,
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
};
static struct User_Input_Type Test4_User =
{

	{
	-1, // this is to indecate user hasn't assigned ID 
	"A",
	100,
	30,
	2,
	2000,
	Male,
	PHD_Holder,
	},
	{
		{
			"EdgesAcademy",
			"Edges123"
		},
	"Edges123"
	}
};
unsigned char Accounts()
{
	Add_Account(&User1);
	Add_Account(&User2);
	//Add_Account(&User3);


}
unsigned char Accounts2()
{
	Add_Account(&User1);
	Add_Account(&User2);
	Add_Account(&User3);


}
unsigned char Verify_User_test(char* UserName, char* Password, int* id_ptr)
{
	unsigned int Customer;
	for (Customer = 0; Customer < MAX_USERS; Customer++)
	{
		if (0 == strcmp(UserName, DB_LoginCredentials[Customer].User_Name))
		{
			if (0 == strcmp(Password, DB_LoginCredentials[Customer].Password))
			{
				//*id_ptr = Customer;
				printf(" login successfull\n");
				return Login_Successful;
			
			}
			else
			{
				*id_ptr = -1;
				return Password_incorrect;
			}
		}
	}
	*id_ptr = -1;
	return UserName_NotFound;
}

/************************************************************************************
* Test ID                : TestCase 1
* Description            : Testing the Add Account Functionality
* Pre-requisits          : There is a User Assigned to DB
* Test inputs            :
*                          Name                         -> Ahmed
*                          Age                          -> 26
*                          DOB_day                      -> 01
*                          DOB_Month                    -> 02
*                          DOB_Year                     -> 1999
*                          Educational_Status           -> Masters_Student
*                          Gender                       -> Male
*                          UserName                     -> EdgesAcademy
*                          Password                     -> Edges123
*                          Password Recheck             -> Edges123
* Test Expected output   : The DB should be updated with the previous inputs correctly
* Reason                 : All inputs are in correct format
*************************************************************************************/
/* init function for Test Suite 1*/
static unsigned char test1_start(void)
{
	unsigned char RET = Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test-1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 1*/
static unsigned char test1_end(void)
{
	unsigned char RET = Delete_Account(current_user_test-1);
	DBM_PrintUsers();
	return !RET;
}
static void TestCase1(void)
{
	unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test1_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test1_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test1_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test1_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test1_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test1_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test1_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test1_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test1_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test1_User.PersonalInfo_Form.id);
}
//
///************************************************************************************
//* Test ID                : TestCase 2
//* Description            : Testing the Add Account Functionality
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :
//*                          Name                         -> Rania
//*                          Age                          -> 54
//*                          DOB_day                      -> 31
//*                          DOB_Month                    -> 12
//*                          DOB_Year                     -> 1970
//*                          Educational_Status           -> PHD_Holder
//*                          Gender                       -> Female
//*                          UserName                     -> EdgesAcademy2024
//*                          Password                     -> Edges_123_$$
//*                          Password Recheck             -> Edges123
//* Test Expected output   : The DB shouldn't be updated with the previous inputs
//* Reason                 : Password inputs mismatch so the suite willn't initiallize 
//*************************************************************************************/
/* init function for Test Suite 2*/
static unsigned char test2_start(void)
{
	unsigned char RET = Add_Account(&Test2_User);
	Test2_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return !RET;
}

/* Closure Function For Test Suite 2*/
static unsigned char test2_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	DBM_PrintUsers();
	return !RET;
}
static void TestCase2(void)
{
	unsigned int Test_id = Test2_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test2_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test2_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test2_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test2_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test2_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test2_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test2_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test2_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test2_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test2_User.PersonalInfo_Form.id);
}
///************************************************************************************
//* Test ID                : TestCase 3
//* Description            : Delete Account after login failure Test
//* Pre-requisits          :  User Assigned in software internally
//* Test inputs            :
//*                          
//* Test Expected output   : Test will not end and test_end will not return 0 
//* Reason                 : Delete function will not be executed 
//*************************************************************************************/
/* init function for Test Suite 3*/
static unsigned char test3_start(void)
{

	printf("\ntest suite execution started \n");

	/*Test2_User.PersonalInfo_Form.id = current_user_test - 1;*/
	DBM_PrintUsers();
	unsigned char RET = Customer_Runner();
	return RET;
	
}

/* Closure Function For Test Suite 3*/
static unsigned char test3_end(void)
{
	unsigned char RET = Delete_Account(current_user_test - 1);
	printf("\ntest suite execution ended \n");
	return RET;
	//return 0;
}
static void TestCase3(void)
{

}


///************************************************************************************
//* Test ID                : TestCase 4
//* Description            : sw will doesnot behave normally as character is input
//* Pre-requisits          :  sing User Assigned internally in software 
//* Test inputs            :

//* Test Expected output   : Test will not end and test_end will not return 0 
//* Reason                 : will not return to main app runner as supposed
//*************************************************************************************/
static unsigned char test4_start(void)
{
	printf("\ntest suite execution started \n");
	unsigned char RET = Verify_Admin();
	return !RET;
}
static unsigned char test4_end(void)
{
	printf("\ntest suite execution ended \n");
	unsigned char RET = Main_App_Runner();
	return RET;
	//return 0;

}
static void TestCase4(void)
{


}
///************************************************************************************
//* Test ID                : TestCase 5
//* Description            : sw allows creating 2 accounts with same username and password 
//* Pre-requisits          : function called to add 2 similar accounts
//* Test inputs            :

//* Test Expected output   : will login with to same account as shouldnot be done 
//* Reason                 : 
//*************************************************************************************/
static unsigned char test5_start(void)
{
	printf("\ntest suite execution started \n");
	unsigned char RET = Accounts();
	printf("\nAccounts added \n");
	DBM_PrintUsers();
	return !RET;
}
static unsigned char test5_end(void)
{
	printf("\ntest suite execution ended \n");
	return 0;
	printf("\ntest suite execution ended \n");

}
static void TestCase5(void)
{

	Verify_User_test(User1.LoginCredentials_Form.LoginCredentials.User_Name, User1.LoginCredentials_Form.LoginCredentials.Password, User1.PersonalInfo_Form.id);
	Verify_User_test(User2.LoginCredentials_Form.LoginCredentials.User_Name, User2.LoginCredentials_Form.LoginCredentials.Password, User2.PersonalInfo_Form.id);
	//Verify_User(User3.LoginCredentials_Form.LoginCredentials.User_Name, User3.LoginCredentials_Form.LoginCredentials.Password, User3.PersonalInfo_Form.id);
	
}
///************************************************************************************
//* Test ID                : TestCase 6
//* Description            : Testing max number of account created
//* Pre-requisits          : call function create 3 accounts
//* Test inputs            :

//* Test Expected output   : only 1 will be created
//* Reason                 : maximum number of created accounts=5
//*************************************************************************************/
static unsigned char test6_start(void)
{
	printf("\ntest suite execution started \n");
	unsigned char RET = Add_Account(&Test1_User);
	printf("\nAccounts added \n");
	DBM_PrintUsers();
	return !RET;
}
static unsigned char test6_end(void)
{
	unsigned char RET = Accounts2();
	DBM_PrintUsers();
	printf("\ntest suite execution ended \n");
	return RET;


}
static void TestCase6(void)
{

} 
///************************************************************************************
//* Test ID                : TestCase 7
//* Description            : logical test educational status shouldnot be  younger than certain age
//* Pre-requisits          : Test1_user
//* Test inputs            :

//* Test Expected output   : fail as phd_holder should be above 25
//* Reason                 : 
//*************************************************************************************/
static unsigned char test7_start(void)
{
	printf("\ntest suite execution started \n");
	unsigned char RET = Add_Account(&Test1_User);
	Test1_User.PersonalInfo_Form.id = current_user_test - 1;
	return !RET;

}
static unsigned char test7_end(void)
{
	printf("\ntest suite execution ended \n");
	return 0;
	

}
static void TestCase7(void)
{
	
	
	    unsigned int Test_id = Test1_User.PersonalInfo_Form.id;
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <17 && DB_info[Test_id].educational_status >= Student);
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <19 && DB_info[Test_id].educational_status >= Faculty_Student);
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <20 && DB_info[Test_id].educational_status >= Graduate);
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <22 && DB_info[Test_id].educational_status >= Masters_Student);
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <24 && DB_info[Test_id].educational_status >= PHD_Student);
		CU_ASSERT_FALSE(Test1_User.PersonalInfo_Form.Age <26 && DB_info[Test_id].educational_status >= PHD_Holder);




	
}
///************************************************************************************
//* Test ID                : TestCase 8
//* Description            : observed mistake phd_student is saved as "thursday"
//* Pre-requisits          : Test3_user
//* Test inputs            :

//* Test Expected output   : success
//* Reason                 : cannot catch bug 
//*************************************************************************************/
static unsigned char test8_start(void)
{
	unsigned char RET = Add_Account(&Test3_User);
	Test3_User.PersonalInfo_Form.id = current_user_test-1;
	DBM_PrintUsers();
	return !RET;
}
static unsigned char test8_end(void)
{

	return 0;
}
static void TestCase8(void)
{
	unsigned int Test_id = Test3_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, Test3_User.PersonalInfo_Form.Age);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_day, Test3_User.PersonalInfo_Form.DOB_day);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_month, Test3_User.PersonalInfo_Form.DOB_month);
	CU_ASSERT_EQUAL(DB_info[Test_id].DOB_year, Test3_User.PersonalInfo_Form.DOB_year);
	CU_ASSERT_EQUAL(DB_info[Test_id].educational_status, Test3_User.PersonalInfo_Form.educational_status);
	CU_ASSERT_EQUAL(DB_info[Test_id].gender, Test3_User.PersonalInfo_Form.gender);
	CU_ASSERT_STRING_EQUAL(DB_info[Test_id].name, Test3_User.PersonalInfo_Form.name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].User_Name, Test3_User.LoginCredentials_Form.LoginCredentials.User_Name);
	CU_ASSERT_STRING_EQUAL(DB_LoginCredentials[Test_id].Password, Test3_User.LoginCredentials_Form.LoginCredentials.Password);
	CU_ASSERT_EQUAL(DB_info[Test_id].id, Test3_User.PersonalInfo_Form.id);
}
///************************************************************************************
//* Test ID                : TestCase 9&10&11
//* Description            : unit testing-testing checking
//* Pre-requisits          : There is a User Assigned to DB
//* Test inputs            :

//* Test Expected output   : The DB shouldn't be updated with the previous inputs
//* Reason                 : Password inputs mismatch so the suite willn't initiallize 
//*************************************************************************************/
static unsigned char test9_start(void)
{
	unsigned char RET = Add_Account(&Test4_User);
	Test4_User.PersonalInfo_Form.id = current_user_test - 1;
	DBM_PrintUsers();
	return RET;
}
static unsigned char test9_end(void)
{
	printf("\ntest suite execution ended \n");
	return 0;
}
static void TestCase9(void)
{
	unsigned int Test_id = Test4_User.PersonalInfo_Form.id;
	CU_ASSERT_TRUE(strlen(DB_info[Test_id].name) > 1 && strlen(DB_info[Test_id].name) < 32);

}
static void TestCase10(void)
{
	unsigned int Test_id = Test4_User.PersonalInfo_Form.id;
	CU_ASSERT_TRUE((DB_info[Test_id].Age) > 1 && DB_info[Test_id].Age < 100);
}
static void TestCase11(void)
{
	unsigned int Test_id = Test4_User.PersonalInfo_Form.id;
	CU_ASSERT_FALSE(DB_info[Test_id].DOB_month == 2 && DB_info[Test_id].DOB_month > 29);
	CU_ASSERT_FALSE((DB_info[Test_id].DOB_month == 4 || DB_info[Test_id].DOB_month == 5 || DB_info[Test_id].DOB_month == 9 || DB_info[Test_id].DOB_month == 10) && DB_info[Test_id].DOB_month > 30);
}
static void TestCase12(void)
{

	unsigned int Test_id = Test4_User.PersonalInfo_Form.id;
	CU_ASSERT_EQUAL(DB_info[Test_id].Age, (2024 - DB_info[Test_id].DOB_year));
}
void Main_Test_Runner(void)
{
	/* initialize the Registry */
	CU_initialize_registry();

	/* Adding Test Suite to the Registry */
	CU_pSuite suite_positive = CU_add_suite("Creaet Valid Account", test1_start, test1_end);
	CU_pSuite suite_negative = CU_add_suite("Creaet InValid Account", test2_start, test2_end);
	CU_pSuite suite_3 = CU_add_suite("suite_3", test3_start, test3_end);
	CU_pSuite suite_4 = CU_add_suite("suite_4", test4_start, test4_end);
	CU_pSuite suite_5 = CU_add_suite("suite_5", test5_start, test5_end);
	CU_pSuite suite_6 = CU_add_suite("suite_6", test6_start, test6_end);
	CU_pSuite suite_7 = CU_add_suite("suite_7", test7_start, test7_end);
	CU_pSuite suite_8 = CU_add_suite("suite_8", test8_start, test8_end);
	CU_pSuite suite_9 = CU_add_suite("suite 9", test9_start, test9_end);

	/* Adding Test Cases to the Test Suite*/
	CU_add_test(suite_positive, "Creat Valid Account", TestCase1);
	 //this suite is expected to fail and not to run due to to the invalid creation of the account 
	CU_add_test(suite_negative, "Creat InValid Account", TestCase2);
	CU_add_test(suite_3, "login_delete", TestCase3);
	CU_add_test(suite_4, "adminlogin_trials", TestCase4);
	CU_add_test(suite_5, "same user&pass", TestCase5);
	CU_add_test(suite_6, "Max_Accounts", TestCase6);
	CU_add_test(suite_7, "Educ&age", TestCase7);
	CU_add_test(suite_8, "thursday", TestCase8);
	
	CU_add_test(suite_9, "Boundry_value_anaylsis", TestCase9);
	CU_add_test(suite_9, "days in month", TestCase10);
	CU_add_test(suite_9, "correct age", TestCase11);
	


	/* Running the Test Suite through Basic Console */
	//CU_basic_set_mode(CU_BRM_VERBOSE);
	//CU_basic_run_tests();

	/* Running the Test Suite through Console interactive */
	  CU_console_run_tests();

	/* Clear the registry after test finished */
	CU_cleanup_registry();
}
