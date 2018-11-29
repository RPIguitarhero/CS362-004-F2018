

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

import java.util.Random; //Kai:library for randomness generation
import java.io.*;


public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   private String testingURL[]= { //Kai:manual testing URL array, add as many as you wish
		   "",
		   " ",
		   "1212f23f123",
		   "255.255.255.255",
           "266.266.231.34",
           "file:///C:/Kai/project.pdf",
		   "https://google.com",
		   "https://amazon.com",
		   "http://google.com",
		   "http:google.com",	   
		   "http://youtube.com",
		   "http://youtube.com/1/view/123?1",
           "http://youtube.com/123f123*12@)_3",                
           "HTTP://sina.com/123f123*12@)_3",
           "http://255.255.255.255:0/test1/file?action=edit&mode=up",
           "ftp://www.google.com:65535/test1?action=edit&mode=up",
           "ftp://blank",
           "http://youtube.com:40/"
           };
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing    
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      for(int i=0;i<testingURL.length;i++)
      {
    	  boolean result=false;
    	  //Kai:the files are so buggy that they often cause termination errors(not exceptions), so I had to do a little trick to deal with them
    	  try{result= urlVal.isValid(testingURL[i]);}
         catch(Error e) //Kai:catch URLs causing error and print them
    	  {System.out.println(testingURL[i]+" caused "+e);continue;}
    	  catch(Exception E) //Kai:just in case something happens, catch URLs causing error and print them
    	  {System.out.println(testingURL[i]+" caused "+E);continue;}
    	//Kai:print URLs with recognizable results
    	  System.out.println(testingURL[i]+" returned result "+result);
      }
      System.out.println("Manual testing done.\n---------------------------------\n");
   }
   
   String validAuthority[] = {//Kai:supposely valid authority array	   
		   "//www.google.com",
           "//youtube.com",
           "//go.au",
           "//0.0.0.0",
           "//255.com",
           "//255.255.255.255"
   };
   
   String validPort[]= {//Kai:supposely valid ports array	   
	   ":0",
	   ":65535",
	   ":40",
	   ""	   //Kai:special case, no port
   };
   
   String validPath[]= {//Kai:supposely valid path array	
	"/",	   
		"/admin",
		"/fe123",
		"/a/b/32",
		"/qwe2=1f",
		"" //Kai:special case, empty path
   };
   
   String validQuery[] = {//Kai:supposely valid query array
		   "view/100?1=option",
		   "?tag=124&order=origianl",
           "1?returnOrignal",
           "c=GB?objectClass?one",
           "?",
           "???option=13",
           "1/3/4/31?type=String",
           "file?action=edit&mode=up",
           "" //Kai:special case, no query
   };

   String validFragments[]= {//Kai:supposely valid fragments array	   
	   "#top",
	   "#newClass=1",
	   "#id*1233",
	   ""	   //Kai:special case, no fragment
   };
   public void testYourFirstPartition()
   {
    //You can use this function to implement your First Partition testing     
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   //Kai:1st partition tests authority and path combination

	   for(int i=0;i<validAuthority.length;i++) //Kai:testing assumed valid authority, ports, and path
	      {
		   for(int j=0;j<validPort.length;j++) 
		   {
			   for(int k=0;k<validPath.length;k++) 
			   {
	    	  boolean result=false;	
	    	  String testingUrl="http:"+validAuthority[i]+validPort[j]+validPath[k];//Kai:assemble the testing URL here
	    	  try{result= urlVal.isValid(testingUrl);}
	         catch(Error e) //Kai:just in case something happens, catch URLs causing error and print them
	    	  {System.out.println(testingUrl+" caused "+e);continue;}
	    	  catch(Exception E) //Kai:just in case something happens, catch URLs causing error and print them
	    	  {System.out.println(testingUrl+" caused "+E);continue;}
	    	//Kai:print URLs with unexpected results
	    	  if(result==false)
	    	  {System.out.println(testingUrl+" returned unexpected result "+result);}
			   }
		   }
	      }
	   
	   System.out.println("Partition testing1 done.\n---------------------------------\n");
   }
   

   public void testYourSecondPartition(){
       //You can use this function to implement your Second Partition testing    
	 //Kai:2nd partition tests query and fragments combination
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   
	   
	   for(int i=0;i<validQuery.length;i++) //Kai:testing assumed valid query and fragments
	      {
		   for(int j=0;j<validFragments.length;j++) 
		   {
	    	  boolean result=false;	
	    	  String testingUrl="http://google.com/"+validQuery[i]+validFragments[j];//Kai:assemble the testing URL here
	    	  try{result= urlVal.isValid(testingUrl);}
	         catch(Error e) //Kai:just in case something happens,catch URLs causing error and print them
	    	  {System.out.println(testingUrl+" caused "+e);continue;}
	    	  catch(Exception E) //Kai:just in case something happens, catch URLs causing error and print them
	    	  {System.out.println(testingUrl+" caused "+E);continue;}
	    	//Kai:print URLs with unexpected results
	    	  if(result==false)
	    	  {System.out.println(testingUrl+" returned unexpected result "+result);}			   
		   }
	      }
	   System.out.println("Partition testing2 done.\n---------------------------------\n");
   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
      //You can use this function for programming based testing
	   /*
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   for(int i=0;i<validAuthority.length;i++) //Kai:testing assumed valid query and fragments
	      {
		   for(int j=0;j<validPort.length;j++) 
		   {
			   for(int k=0;k<validPath.length;k++) 
			   {
				   for(int l=0;l<validQuery.length;l++) 
				   {
					   for(int m=0;m<validFragments.length;m++) 
					   {
						   	boolean result=false;	
						   	String testingUrl="http:"+validAuthority[i]+validPort[j]+validPath[k]+validQuery[l]+validFragments[m];//Kai:assemble the testing URL here
						   	try{result= urlVal.isValid(testingUrl);}
						   	catch(Error e) //Kai:just in case something happens,catch URLs causing error and print them
						   	{System.out.println(testingUrl+" caused "+e);continue;}
						   	//Kai:print URLs with unexpected results
						   	if(result==false)
						   	{System.out.println(testingUrl+" returned unexpected result "+result);}			   
					   }
				   }
			   }
		   }
	      }
	   System.out.println("IsValid testing done.\n---------------------------------\n");*/
   }
   


}
