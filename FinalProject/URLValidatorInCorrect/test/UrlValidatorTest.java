

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
           "ftp://blank"

           };
   public void testManualTest()
   {
//You can use this function to implement your manual testing    
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      for(int i=0;i<testingURL.length;i++)
      {
    	  boolean result=false;
    	  //Kai:the files are so buggy that they often cause termination errors(not exceptions), so I had to do a little trick to mark the passed resultes as exceptions
    	  try{result= urlVal.isValid(testingURL[i]);}
         catch(Error e) 
    	  {System.out.println(testingURL[i]+" caused "+e);continue;}
    	  
    	  System.out.println(testingURL[i]+" returned result "+result);
      }
      
   }
   
   
   public void testYourFirstPartition()
   {
    //You can use this function to implement your First Partition testing     

   }
   
   public void testYourSecondPartition(){
       //You can use this function to implement your Second Partition testing    

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
      //You can use this function for programming based testing

   }
   


}
