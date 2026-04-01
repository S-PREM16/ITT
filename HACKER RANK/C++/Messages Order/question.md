Class Message is required to store a text value of type std::string and provide a public getter const string& get_text() which is expected to return this text value. Besides that, it should implement the < operator that will be used in fix_order() method of the recipient to fix the order of received messages. Feel free to implement any other methods and class/instance variables. In particular, you can implement any additional constructors, but make sure that you provide an empty constructor, i.e. the one without arguments.

Class MessageFactory is required to have an empty constructor, and implement a method Message create_message(const string& text) that is expected to return a Message object storing the value of text argument. Feel free to implement any other methods and class/instance variables of this class.

The locked code template will act as follows. First, it creates objects message_factory and recipient. These objects are of types MessageFactory and Recipient respectively. Then, it reads messages from the standard input, and then it will use the provided Network class to simulate sending the messages to the recipient. The Network class randomly shuffles the passes messages and then it passes them to the recipient using recipient.receive(const Message&) method. After all messages are delivered, the recipient uses its own method print_messages to print all the received messages to the standard output, and just before doing that, it uses its own fix_order method to fix the order of retrieved messages. For that purpose, it uses std::sort() algorithm to sort the std::vector of received messages and this is the reason your Message class implementation has to provide the < operator.

Input Format

The input is read by the provided locked code template. It contains several lines of text messages in the order that they will be sent over the network.

Constraints

There will be at most  lines in the input.
Each line will contain at most  characters
Output Format

The output should be produced by the provided locked code template and it is produced as described in details in the statement. The expected order of printed messages is the same as the one in the input.

Sample Input 0

Alex
Hello Monique!
What'up?
Not much :(
Sample Output 0

Alex
Hello Monique!
What'up?
Not much :(
Language
C++20
More
575859606162636465666768697071727374757677787980818283
    recipient.print_messages();
}

39class Recipient {
Line: 83 Col: 1

Test against custom input
Congratulations!

You have passed the sample test cases. Click the submit button to run your code against all the test cases.


Sample Test case 0
Input (stdin)
Alex
Hello Monique!
What'up?
Not much :(
Your Output (stdout)
Alex
Hello Monique!
What'up?
Not much :(
Expected Output
Alex
Hello Monique!
What'up?
Not much :(
Blog
