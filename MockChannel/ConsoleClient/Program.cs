﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleClient
{
  class Program
  {
    static void Main(string[] args)
    {
      Shim shim = new Shim();
      shim.PostMessage("hello from client");
      Console.Write("\n  {0}", shim.GetMessage());
    }
  }
}
