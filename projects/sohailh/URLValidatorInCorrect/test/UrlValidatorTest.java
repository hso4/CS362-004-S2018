
import org.junit.Test;

import junit.framework.TestCase;

import static java.lang.System.exit;

import java.util.concurrent.ThreadLocalRandom;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }



   public void testManualTest()
   {
      //You can use this function to implement your manual testing

      System.out.println("START OF MANUAL TESTING");

      UrlValidator urlTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
      String testUrl = "http://www.google.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test passed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test failed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "https://www.google.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test passed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test failed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "HTTP://www.google.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test passed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test failed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "http:/www.google.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "http:www.google.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "http://www.speedtest.net";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test passed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test failed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      testUrl = "http:///www.speedtest.net";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      testUrl = "http:/www.speedtest.net";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      testUrl = "http:www.speedtest.net";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }


      testUrl = "http://www.yahoo.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test passed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test failed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      testUrl = "http:/www.yahoo.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      testUrl = "http:///www.yahoo.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }
      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }

      testUrl = "http:////www.yahoo.com";
      try {
         System.out.println("___________________________________________");
         if(urlTest.isValid(testUrl)) {
            System.out.println("URL: " + testUrl + " is valid!");
            System.out.println("Manual test failed!");
         }
         else{
            System.out.println("URL: " + testUrl + " is not valid!");
            System.out.println("Manual test passed!");
         }

      }
      catch (Exception any)
      {
         System.out.println("EXCEPTION CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");
      }
      catch (Error any)
      {
         System.out.println("ERROR CAUGHT - " + any);
         System.out.println("URL: " + testUrl + " is not valid!");
         System.out.println("Manual test failed!");

      }
      System.out.println("___________________________________________");
      System.out.println("\nEND OF MANUAL TESTING");

   }

   ///*
  public void testYourFirstPartition()
   {
    //You can use this function to implement your First Partition testing
      // This will test if the scheme of the URL is valid
      UrlValidator schemeTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      String validScheme = "http://amazon.com";
      String invalidScheme = "ttph://amazon.com";

      // TEST CORRECT SCHEME
      if(schemeTest.isValid(validScheme)) {
         System.out.println("Scheme: " + validScheme + " is valid. TEST PASSED");
      }

      else {
         System.out.println("Scheme: " + validScheme + " is not valid. TEST FAILED");
      }

      // TEST INCORRECT SCHEME
      if(schemeTest.isValid(invalidScheme)) {
         System.out.println("Scheme: " + invalidScheme +  " is valid. TEST FAILED");
      }

      else {
         System.out.println("Scheme: " + invalidScheme + " is not valid. TEST PASSED");
      }
         

   }
   
   public void testYourSecondPartition(){
       //You can use this function to implement your Second Partition testing   
   
   // This will test if the authority of the URL is valid
   UrlValidator authTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

   String validAuth = "http://google.com";
   String invalidAuth = "http://goo gle.com";

   // TEST CORRECT AUTHORITY
   if(authTest.isValid(validAuth)) {
      System.out.println("Authority: " + validAuth + " is valid. TEST PASSED");
   }

   else {
      System.out.println("Authority: " + validAuth + " is invalid. TEST FAILED");
   }

   // TEST INCORRECT AUTHORITY
   if(authTest.isValid(invalidAuth)) {
      System.out.println("Authority: " + invalidAuth + " is valid. TEST FAILED");
   }

   else {
      System.out.println("Authority: " + invalidAuth + " is invalid. TEST PASSED");
   }
 

   }
   //You need to create more test cases for your Partitions if you need to 


   public void testYourThirdPartition() {

      // This will test for valid paths
      UrlValidator pathTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      String validPath = "http://amazon.com/file1";
      String invalidPath = "http://amazon.com///file1";

      // TEST CORRECT PATH
      if(pathTest.isValid(validPath)) {
         System.out.println("Path: " +  validPath + " is valid. TEST PASSED");
      }

      else {
         System.out.println("Path: " + validPath + " is invalid. TEST FAILED");
      }

      // TEST INCORRECT PATH
      if(pathTest.isValid(invalidPath)) {
         System.out.println("Path: " + invalidPath + " is valid. TEST FAILED");
      }

      else {
         System.out.println("Path: " + invalidPath + " is invalid. TEST PASSED");
      }
   }

   public void testYourFourthPartition() {

      // This will test for valid queries
      UrlValidator queryTest = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);

      String validQuery = "http://amazon.com/file1/ask?question/answer";
      String invalidQuery = "http://amazon.com/file1/ask?? question/noanswer";

      // TEST CORRECT QUERY
      if(queryTest.isValid(validQuery)) {
         System.out.println("Query: " + validQuery + " is valid. TEST PASSED");
      }

      else {
         System.out.println("Query: " + validQuery + " is invalid. TEST FAILED");
      }

      // TEST INCORRECT QUERY
      if(queryTest.isValid(invalidQuery)) {
         System.out.println("Query: " + invalidQuery + " is valid. TEST FAILED");
      }

      else {
         System.out.println("Query: " + invalidQuery + " is invalid. TEST PASSED");
      }

   }
   //You need to create more test cases for your Partitions if you need to

   public void testIsValid()
   {
      //You can use this function for programming based testing

      //You can use this function for programming based testing
      
      String[] validSchemes = {"http", "https"};
      
      boolean isValid = true; 
      UrlValidator urlValidator = new UrlValidator(validSchemes, UrlValidator.NO_FRAGMENTS);
      int randomNum;
     
      boolean testResult = true;
      
      String[] goodScheme = {"http://", "ftp://", "https://", "sftp://"};   
   
      String[] badScheme = {"jjjj://", "/twt:", ":////", "http"};
      
      String[] goodUrl = {"www.twitter.com", "www.facebook.com", "www.google.com", "main.oregonstate.edu"};
      
      String[] badUrl = {"999.999.999.999", "com.ww", "aaa.facebook.com", "...//www/com"};
      
      String[] goodPath = {"/path","/1234","/path123/","/123?query&=this"};
      
      String[] badPath = {"pathProblem","/.../","/324//32","/pathOk?//notOk"};

      for(int i = 0; i < 100; i++) {

         StringBuilder URLTest = new StringBuilder();
         isValid = true;
         for(int j = 0; j < 3; j++) {
            randomNum = ThreadLocalRandom.current().nextInt(1, 3);
            if(j == 0){
               if(randomNum == 1) {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);
                  URLTest.append(goodScheme[randomNum]);
                  
               }else {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);

                  URLTest.append(badScheme[randomNum]);
                  isValid = false;
               }
            }
            
            if(j == 1) {
               if(randomNum == 1) {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);

                  URLTest.append(goodUrl[randomNum]);
                  
               }else {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);

                  URLTest.append(badUrl[randomNum]);
                  isValid = false;
               }
            }         
            
            if(j == 2) {
               if(randomNum == 1) {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);

                  URLTest.append(goodPath[randomNum]);
                  
               }else {
                  randomNum = ThreadLocalRandom.current().nextInt(0, 4);

                  URLTest.append(badPath[randomNum]);
                  isValid = false;
               }              
            }
         } 
         
         String urlString = URLTest.toString();
         testResult = urlValidator.isValid(urlString);
         System.out.printf("Test Case: %d\n", i);
         if(testResult == true) {
            if(isValid == false) {
               System.out.println("TEST FAILED! Expected: Fail, Result: Pass");
               System.out.printf("URL: %s\n\n", urlString);
               
            }
          
         } else {
            if(isValid == true) {
               
               System.out.println("TEST FAILED! Expected: Pass, Result: Fail");
               System.out.printf("URL: %s\n\n", urlString);
            }
         }
         
         if(testResult && isValid) {
            System.out.println("TEST PASSED! Good URL");
            System.out.printf("URL: %s\n\n", urlString);
         }
         
         if(!testResult && !isValid) {
            
            System.out.println("TEST PASSED! Bad URL");
            System.out.printf("URL: %s\n\n", urlString);
         }
         
      }        


   }//*/



}
