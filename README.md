# JSON2Text
JSON to swift code converter.

## Introduction

Sometimes we need to create stubs from JSON file to test our Models. However, creating the stubs manually is not a good idea - it takes time, hard to make sure correctness, and sometimes impossible to update.

There's another way, we could simply copy & paste the JSON file into our code, and make some slight changes to convert it into a dictionary. However this brings another issue. We already know that swift compiler is extremely slow when doing complex type inference.

That's what this utility came for. This utility simply converts the JSON file into a giant string, so that you could use some other utility classes to parse it into dictionary or JSON object. This is not pretty, but it works, and the compiler becoming 'swift' when compared to complex dictionary.

Here is a very simple sample:

```
struct SomeModelStubs {
  private static var text =
    "{" +
    "  \"somekey\": \"some value\"," +
    "....." +
    ""  // just replace this var text into our generated code
    
  static var stub: JSON {  // we're using SwiftyJSON for this sample code
    return JSON(data: text.dataUsingEncoding(NSUTF8StringEncoding, allowLossyConversion: false)!)
  }
}
```

## How to Build

To build this utility, just clone or download the source code, and run this command in the Terminal.

`clang++ -o JSON2Text JSON2Text.cpp`

It will produce an executable called JSON2Text

## How to Use

This utility reads from console and outputs to console. So that we could use pipe to easily read and write to file.

`cat YOUR_JSON_FILE.json | ./JSON2Text > MyOutput.swift`

If everything's good, you'll get a working MyOutput.swift with only one single giant string.

