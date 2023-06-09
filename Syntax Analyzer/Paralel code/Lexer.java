// DO NOT EDIT
// Generated by JFlex 1.8.2 http://jflex.de/
// source: Tarea5_3/Lexer.flex

package Tarea5_3;
import static Tarea5_3.Tokens.*;

// See https://github.com/jflex-de/jflex/issues/222
@SuppressWarnings("FallThrough")
class Lexer {

  /** This character denotes the end of file. */
  public static final int YYEOF = -1;

  /** Initial size of the lookahead buffer. */
  private static final int ZZ_BUFFERSIZE = 16384;

  // Lexical states.
  public static final int YYINITIAL = 0;

  /**
   * ZZ_LEXSTATE[l] is the state in the DFA for the lexical state l
   * ZZ_LEXSTATE[l+1] is the state in the DFA for the lexical state l
   *                  at the beginning of a line
   * l is of the form l = 2*k, k a non negative integer
   */
  private static final int ZZ_LEXSTATE[] = {
     0, 0
  };

  /**
   * Top-level table for translating characters to character classes
   */
  private static final int [] ZZ_CMAP_TOP = zzUnpackcmap_top();

  private static final String ZZ_CMAP_TOP_PACKED_0 =
    "\1\0\37\u0100\1\u0200\267\u0100\10\u0300\u1020\u0100";

  private static int [] zzUnpackcmap_top() {
    int [] result = new int[4352];
    int offset = 0;
    offset = zzUnpackcmap_top(ZZ_CMAP_TOP_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackcmap_top(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  /**
   * Second-level tables for translating characters to character classes
   */
  private static final int [] ZZ_CMAP_BLOCKS = zzUnpackcmap_blocks();

  private static final String ZZ_CMAP_BLOCKS_PACKED_0 =
    "\11\0\1\1\1\2\2\3\1\1\22\0\1\4\1\5"+
    "\1\6\1\7\1\0\1\10\1\11\1\12\2\13\1\14"+
    "\1\15\1\4\1\16\1\17\1\20\3\21\1\22\6\21"+
    "\2\13\1\23\1\24\1\25\2\0\1\26\1\27\1\30"+
    "\1\31\1\32\1\33\1\34\1\35\1\36\1\37\1\40"+
    "\1\41\1\42\1\43\1\44\1\45\1\46\1\47\1\50"+
    "\1\51\1\52\1\53\1\54\1\55\1\56\1\57\1\13"+
    "\1\0\1\13\1\15\1\37\1\0\1\60\1\61\1\62"+
    "\1\63\1\64\1\65\1\66\1\67\1\70\1\37\1\71"+
    "\1\72\1\73\1\74\1\75\1\76\1\77\1\100\1\101"+
    "\1\102\1\103\1\104\1\105\1\106\1\107\1\110\1\13"+
    "\1\111\1\13\7\0\1\3\u01a2\0\2\3\326\0\u0100\3";

  private static int [] zzUnpackcmap_blocks() {
    int [] result = new int[1024];
    int offset = 0;
    offset = zzUnpackcmap_blocks(ZZ_CMAP_BLOCKS_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackcmap_blocks(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }

  /**
   * Translates DFA states to action switch labels.
   */
  private static final int [] ZZ_ACTION = zzUnpackAction();

  private static final String ZZ_ACTION_PACKED_0 =
    "\1\0\1\1\1\2\1\3\1\4\1\1\1\5\1\6"+
    "\2\1\1\7\3\6\1\7\1\6\1\10\1\11\1\12"+
    "\1\11\51\13\1\1\1\11\1\0\1\14\1\5\1\4"+
    "\1\0\1\14\1\15\1\0\1\16\1\13\1\16\3\13"+
    "\1\16\15\13\1\16\2\13\1\16\25\13\1\16\1\13"+
    "\1\16\1\13\1\16\106\13\1\16\2\13\1\16\2\13"+
    "\1\16\3\13\1\16\21\13\1\17\115\13\1\16\44\13"+
    "\2\16\12\13";

  private static int [] zzUnpackAction() {
    int [] result = new int[346];
    int offset = 0;
    offset = zzUnpackAction(ZZ_ACTION_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAction(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  /**
   * Translates a state to a row index in the transition table
   */
  private static final int [] ZZ_ROWMAP = zzUnpackRowMap();

  private static final String ZZ_ROWMAP_PACKED_0 =
    "\0\0\0\112\0\224\0\336\0\u0128\0\u0172\0\112\0\u01bc"+
    "\0\u0206\0\u0250\0\112\0\u029a\0\112\0\u02e4\0\u032e\0\u0378"+
    "\0\u03c2\0\u040c\0\u0128\0\u0456\0\u04a0\0\u04ea\0\u0534\0\u057e"+
    "\0\u05c8\0\u0612\0\u065c\0\u06a6\0\u06f0\0\u073a\0\u0784\0\u07ce"+
    "\0\u0818\0\u0862\0\u08ac\0\u08f6\0\u0940\0\u098a\0\u09d4\0\u0a1e"+
    "\0\u0a68\0\u0ab2\0\u0afc\0\u0b46\0\u0b90\0\u0bda\0\u0c24\0\u0c6e"+
    "\0\u0cb8\0\u0d02\0\u0d4c\0\u0d96\0\u0de0\0\u0e2a\0\u0e74\0\u0ebe"+
    "\0\u0f08\0\u0f52\0\u0f9c\0\u0fe6\0\u1030\0\u107a\0\112\0\u0172"+
    "\0\u0172\0\u01bc\0\112\0\u0250\0\u0250\0\u032e\0\u032e\0\112"+
    "\0\u10c4\0\u110e\0\u1158\0\u11a2\0\u11ec\0\u1236\0\u1280\0\u12ca"+
    "\0\u1314\0\u135e\0\u13a8\0\u13f2\0\u143c\0\u1486\0\u14d0\0\u151a"+
    "\0\u1564\0\u15ae\0\u15f8\0\u1642\0\u168c\0\u16d6\0\u1720\0\u176a"+
    "\0\u17b4\0\u17fe\0\u1848\0\u1892\0\u18dc\0\u1926\0\u1970\0\u19ba"+
    "\0\u1a04\0\u1a4e\0\u1a98\0\u1ae2\0\u1b2c\0\u1b76\0\u1bc0\0\u1c0a"+
    "\0\u1c54\0\u1c9e\0\u1ce8\0\u1d32\0\u06a6\0\u1d7c\0\u1dc6\0\u1e10"+
    "\0\u1e5a\0\u1ea4\0\u1eee\0\u1f38\0\u1f82\0\u1fcc\0\u2016\0\u2060"+
    "\0\u20aa\0\u20f4\0\u213e\0\u2188\0\u21d2\0\u221c\0\u2266\0\u22b0"+
    "\0\u22fa\0\u2344\0\u238e\0\u23d8\0\u2422\0\u246c\0\u24b6\0\u2500"+
    "\0\u254a\0\u2594\0\u25de\0\u2628\0\u2672\0\u26bc\0\u2706\0\u2750"+
    "\0\u279a\0\u27e4\0\u282e\0\u2878\0\u28c2\0\u290c\0\u2956\0\u29a0"+
    "\0\u29ea\0\u2a34\0\u2a7e\0\u2ac8\0\u2b12\0\u2b5c\0\u2ba6\0\u2bf0"+
    "\0\u2c3a\0\u2c84\0\u2cce\0\u2d18\0\u2d62\0\u2dac\0\u2df6\0\u2e40"+
    "\0\u2e8a\0\u2ed4\0\u2f1e\0\u2f68\0\u2fb2\0\u2ffc\0\u3046\0\u3090"+
    "\0\u30da\0\u3124\0\u316e\0\u31b8\0\u3202\0\u324c\0\u3296\0\u32e0"+
    "\0\u332a\0\u3374\0\u33be\0\u3408\0\u3452\0\u349c\0\u34e6\0\u3530"+
    "\0\u357a\0\u35c4\0\u360e\0\u3658\0\u36a2\0\u36ec\0\u3736\0\u3780"+
    "\0\u37ca\0\u3814\0\u385e\0\u38a8\0\u38f2\0\u393c\0\u3986\0\u39d0"+
    "\0\u3a1a\0\u3a64\0\u3aae\0\u06a6\0\u3af8\0\u3b42\0\u3b8c\0\u3bd6"+
    "\0\u3c20\0\u3c6a\0\u3cb4\0\u3cfe\0\u3d48\0\u3d92\0\u3ddc\0\u3e26"+
    "\0\u349c\0\u3e70\0\u35c4\0\u3eba\0\u3f04\0\u3f4e\0\u3f98\0\u3fe2"+
    "\0\u402c\0\u4076\0\u40c0\0\u410a\0\u4154\0\u419e\0\u41e8\0\u4232"+
    "\0\u427c\0\u42c6\0\u4310\0\u435a\0\u43a4\0\u43ee\0\u4438\0\u4482"+
    "\0\u44cc\0\u4516\0\u4560\0\u45aa\0\u45f4\0\u463e\0\u4688\0\u46d2"+
    "\0\u471c\0\u4766\0\u47b0\0\u47fa\0\u4844\0\u488e\0\u48d8\0\u4922"+
    "\0\u496c\0\u49b6\0\u4a00\0\u4a4a\0\u4a94\0\u4ade\0\u4b28\0\u4b72"+
    "\0\u4bbc\0\u4c06\0\u4c50\0\u4c9a\0\u4ce4\0\u4d2e\0\u4d78\0\u4dc2"+
    "\0\u4e0c\0\u4e56\0\u4ea0\0\u4eea\0\u4f34\0\u4f7e\0\u4fc8\0\u5012"+
    "\0\u505c\0\u50a6\0\u50f0\0\u513a\0\u5184\0\u51ce\0\u5218\0\u5262"+
    "\0\u52ac\0\u52f6\0\u5340\0\u538a\0\u53d4\0\u541e\0\u5468\0\u54b2"+
    "\0\u54fc\0\u5546\0\u5590\0\u55da\0\u5624\0\u566e\0\u56b8\0\u5702"+
    "\0\u574c\0\u5796\0\u57e0\0\u582a\0\u5874\0\u58be\0\u5908\0\u5952"+
    "\0\u599c\0\u59e6\0\u5a30\0\u5a7a\0\u5ac4\0\u5b0e\0\u5b58\0\u5ba2"+
    "\0\u5bec\0\u5c36\0\u5c80\0\u5cca\0\u5d14\0\u5d5e\0\u5da8\0\u5df2"+
    "\0\u5e3c\0\u5e86";

  private static int [] zzUnpackRowMap() {
    int [] result = new int[346];
    int offset = 0;
    offset = zzUnpackRowMap(ZZ_ROWMAP_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackRowMap(String packed, int offset, int [] result) {
    int i = 0;  /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int high = packed.charAt(i++) << 16;
      result[j++] = high | packed.charAt(i++);
    }
    return j;
  }

  /**
   * The transition table of the DFA
   */
  private static final int [] ZZ_TRANS = zzUnpackTrans();

  private static final String ZZ_TRANS_PACKED_0 =
    "\1\2\1\3\1\4\1\0\1\3\1\5\1\6\1\7"+
    "\1\10\1\11\1\12\1\13\1\14\1\15\1\16\1\17"+
    "\1\20\2\21\1\22\1\23\1\24\1\25\1\26\1\27"+
    "\1\30\1\31\1\32\1\33\1\34\1\35\2\34\1\36"+
    "\1\34\1\37\1\40\1\41\1\42\1\43\1\44\1\45"+
    "\1\46\1\47\1\50\1\34\1\51\1\34\1\52\1\53"+
    "\1\54\1\55\1\56\1\57\1\60\1\34\1\61\1\34"+
    "\1\62\1\34\1\63\1\64\1\65\1\66\1\67\1\70"+
    "\1\71\1\72\1\73\1\74\1\34\1\75\1\34\1\76"+
    "\113\0\1\3\2\0\1\3\107\0\1\4\133\0\1\77"+
    "\65\0\1\100\2\0\3\100\1\101\103\100\26\0\63\102"+
    "\12\0\1\103\100\0\1\104\2\0\7\104\1\105\77\104"+
    "\14\0\1\15\3\0\1\7\112\0\2\21\110\0\2\106"+
    "\103\0\1\7\3\0\1\7\110\0\1\107\1\0\2\21"+
    "\112\0\1\110\1\77\111\0\1\77\1\110\105\0\2\34"+
    "\3\0\15\34\1\111\4\34\1\112\1\34\1\113\2\34"+
    "\1\114\16\34\1\115\4\34\1\116\1\34\1\117\2\34"+
    "\1\120\2\34\22\0\2\34\3\0\21\34\1\121\30\34"+
    "\1\122\10\34\22\0\2\34\3\0\1\123\12\34\1\124"+
    "\2\34\1\125\13\34\1\126\6\34\1\127\2\34\1\130"+
    "\2\34\1\131\13\34\22\0\2\34\3\0\4\34\1\132"+
    "\3\34\1\133\5\34\1\134\17\34\1\135\3\34\1\136"+
    "\4\34\1\137\13\34\22\0\2\34\3\0\13\34\1\140"+
    "\1\34\1\141\11\34\1\142\14\34\1\143\1\34\1\144"+
    "\11\34\1\145\2\34\22\0\2\34\3\0\1\146\7\34"+
    "\1\147\5\34\1\150\2\34\1\151\10\34\1\152\7\34"+
    "\1\153\1\34\1\154\2\34\1\155\2\34\1\156\10\34"+
    "\22\0\2\34\3\0\13\34\1\157\2\34\1\160\2\34"+
    "\1\161\22\34\1\162\2\34\1\163\2\34\1\164\10\34"+
    "\22\0\2\34\3\0\63\34\22\0\2\34\3\0\5\34"+
    "\1\165\6\34\1\166\1\167\4\34\1\165\14\34\1\165"+
    "\5\34\1\170\1\171\4\34\1\165\7\34\22\0\2\34"+
    "\3\0\1\172\3\34\1\173\11\34\1\174\13\34\1\175"+
    "\3\34\1\176\10\34\1\177\13\34\22\0\2\34\3\0"+
    "\16\34\1\200\5\34\1\201\22\34\1\202\5\34\1\203"+
    "\5\34\22\0\2\34\3\0\5\34\1\204\7\34\1\165"+
    "\3\34\1\165\15\34\1\205\6\34\1\165\3\34\1\165"+
    "\10\34\22\0\2\34\3\0\1\206\12\34\1\207\5\34"+
    "\1\210\10\34\1\211\11\34\1\212\5\34\1\213\10\34"+
    "\22\0\2\34\3\0\24\34\1\214\30\34\1\215\5\34"+
    "\22\0\2\34\3\0\1\216\3\34\1\217\25\34\1\220"+
    "\3\34\1\221\24\34\22\0\2\34\3\0\10\34\1\222"+
    "\7\34\1\223\2\34\1\224\2\34\1\225\13\34\1\226"+
    "\6\34\1\227\2\34\1\230\2\34\1\231\3\34\22\0"+
    "\2\34\3\0\4\34\1\232\3\34\1\233\10\34\1\234"+
    "\6\34\1\235\5\34\1\236\3\34\1\237\7\34\1\240"+
    "\6\34\1\241\1\34\22\0\2\34\3\0\15\34\1\242"+
    "\30\34\1\243\14\34\22\0\2\34\3\0\16\34\1\244"+
    "\30\34\1\245\13\34\22\0\2\34\3\0\7\34\1\246"+
    "\1\247\30\34\1\250\1\251\20\34\22\0\2\34\3\0"+
    "\10\34\1\252\31\34\1\253\20\34\22\0\2\34\3\0"+
    "\46\34\1\115\4\34\1\116\1\34\1\117\2\34\1\120"+
    "\2\34\22\0\2\34\3\0\52\34\1\122\10\34\22\0"+
    "\2\34\3\0\32\34\1\126\6\34\1\127\2\34\1\130"+
    "\2\34\1\131\13\34\22\0\2\34\3\0\36\34\1\135"+
    "\3\34\1\136\4\34\1\137\13\34\22\0\2\34\3\0"+
    "\44\34\1\143\1\34\1\144\11\34\1\145\2\34\22\0"+
    "\2\34\3\0\32\34\1\152\7\34\1\153\1\34\1\154"+
    "\2\34\1\155\2\34\1\156\10\34\22\0\2\34\3\0"+
    "\44\34\1\162\2\34\1\163\2\34\1\164\10\34\22\0"+
    "\2\34\3\0\37\34\1\165\5\34\1\170\1\171\4\34"+
    "\1\165\7\34\22\0\2\34\3\0\32\34\1\175\3\34"+
    "\1\176\10\34\1\177\13\34\22\0\2\34\3\0\47\34"+
    "\1\202\5\34\1\203\5\34\22\0\2\34\3\0\37\34"+
    "\1\205\6\34\1\165\3\34\1\165\10\34\22\0\2\34"+
    "\3\0\32\34\1\211\11\34\1\212\5\34\1\213\10\34"+
    "\22\0\2\34\3\0\55\34\1\215\5\34\22\0\2\34"+
    "\3\0\32\34\1\220\3\34\1\221\24\34\22\0\2\34"+
    "\3\0\42\34\1\226\6\34\1\227\2\34\1\230\2\34"+
    "\1\231\3\34\22\0\2\34\3\0\36\34\1\236\3\34"+
    "\1\237\7\34\1\240\6\34\1\241\1\34\22\0\2\34"+
    "\3\0\46\34\1\243\14\34\22\0\2\34\3\0\47\34"+
    "\1\245\13\34\22\0\2\34\3\0\41\34\1\250\1\251"+
    "\20\34\22\0\2\34\3\0\42\34\1\253\20\34\112\0"+
    "\1\103\21\0\2\34\3\0\3\34\1\165\57\34\22\0"+
    "\2\34\3\0\22\34\1\254\40\34\22\0\2\34\3\0"+
    "\23\34\1\255\37\34\22\0\2\34\3\0\10\34\1\256"+
    "\52\34\22\0\2\34\3\0\35\34\1\165\25\34\22\0"+
    "\2\34\3\0\53\34\1\257\7\34\22\0\2\34\3\0"+
    "\54\34\1\260\6\34\22\0\2\34\3\0\42\34\1\261"+
    "\20\34\22\0\2\34\3\0\4\34\1\262\56\34\22\0"+
    "\2\34\3\0\36\34\1\263\24\34\22\0\2\34\3\0"+
    "\22\34\1\264\1\265\37\34\22\0\2\34\3\0\1\266"+
    "\1\34\1\165\60\34\22\0\2\34\3\0\15\34\1\267"+
    "\6\34\1\270\36\34\22\0\2\34\3\0\53\34\1\271"+
    "\1\272\6\34\22\0\2\34\3\0\32\34\1\273\30\34"+
    "\22\0\2\34\3\0\32\34\1\274\1\34\1\165\1\34"+
    "\1\275\24\34\22\0\2\34\3\0\46\34\1\276\6\34"+
    "\1\277\5\34\22\0\2\34\3\0\5\34\1\300\5\34"+
    "\1\165\47\34\22\0\2\34\3\0\22\34\1\301\40\34"+
    "\22\0\2\34\3\0\24\34\1\302\36\34\22\0\2\34"+
    "\3\0\37\34\1\303\4\34\1\165\16\34\22\0\2\34"+
    "\3\0\53\34\1\304\7\34\22\0\2\34\3\0\55\34"+
    "\1\305\5\34\22\0\2\34\3\0\10\34\1\204\11\34"+
    "\1\264\40\34\22\0\2\34\3\0\3\34\1\306\20\34"+
    "\1\307\36\34\22\0\2\34\3\0\2\34\1\310\20\34"+
    "\1\311\37\34\22\0\2\34\3\0\42\34\1\205\10\34"+
    "\1\271\7\34\22\0\2\34\3\0\35\34\1\312\17\34"+
    "\1\313\5\34\22\0\2\34\3\0\34\34\1\314\17\34"+
    "\1\315\6\34\22\0\2\34\3\0\13\34\1\316\47\34"+
    "\22\0\2\34\3\0\6\34\1\317\6\34\1\320\45\34"+
    "\22\0\2\34\3\0\21\34\1\165\41\34\22\0\2\34"+
    "\3\0\16\34\1\307\44\34\22\0\2\34\3\0\44\34"+
    "\1\321\16\34\22\0\2\34\3\0\40\34\1\322\5\34"+
    "\1\323\14\34\22\0\2\34\3\0\47\34\1\324\13\34"+
    "\22\0\2\34\3\0\52\34\1\165\10\34\22\0\2\34"+
    "\3\0\47\34\1\313\13\34\22\0\2\34\3\0\16\34"+
    "\1\325\44\34\22\0\2\34\3\0\23\34\1\326\37\34"+
    "\22\0\2\34\3\0\10\34\1\111\52\34\22\0\2\34"+
    "\3\0\47\34\1\327\13\34\22\0\2\34\3\0\54\34"+
    "\1\330\6\34\22\0\2\34\3\0\42\34\1\115\20\34"+
    "\22\0\2\34\3\0\17\34\1\331\43\34\22\0\2\34"+
    "\3\0\2\34\1\332\14\34\1\333\3\34\1\334\37\34"+
    "\22\0\2\34\3\0\50\34\1\335\12\34\22\0\2\34"+
    "\3\0\34\34\1\336\13\34\1\337\3\34\1\334\6\34"+
    "\22\0\2\34\3\0\1\34\1\340\12\34\1\341\46\34"+
    "\22\0\2\34\3\0\15\34\1\342\45\34\22\0\2\34"+
    "\3\0\15\34\1\343\45\34\22\0\2\34\3\0\33\34"+
    "\1\344\11\34\1\345\15\34\22\0\2\34\3\0\46\34"+
    "\1\346\14\34\22\0\2\34\3\0\46\34\1\347\14\34"+
    "\22\0\2\34\3\0\15\34\1\350\5\34\1\165\37\34"+
    "\22\0\2\34\3\0\13\34\1\351\47\34\22\0\2\34"+
    "\3\0\46\34\1\352\5\34\1\165\6\34\22\0\2\34"+
    "\3\0\44\34\1\353\16\34\22\0\2\34\3\0\5\34"+
    "\1\165\55\34\22\0\2\34\3\0\37\34\1\165\23\34"+
    "\22\0\2\34\3\0\22\34\1\256\1\265\37\34\22\0"+
    "\2\34\3\0\16\34\1\354\44\34\22\0\2\34\3\0"+
    "\10\34\1\355\52\34\22\0\2\34\3\0\53\34\1\261"+
    "\1\272\6\34\22\0\2\34\3\0\47\34\1\356\13\34"+
    "\22\0\2\34\3\0\42\34\1\357\20\34\22\0\2\34"+
    "\3\0\10\34\1\360\52\34\22\0\2\34\3\0\42\34"+
    "\1\361\20\34\22\0\2\34\3\0\10\34\1\316\4\34"+
    "\1\362\45\34\22\0\2\34\3\0\6\34\1\363\14\34"+
    "\1\364\37\34\22\0\2\34\3\0\42\34\1\321\3\34"+
    "\1\365\14\34\22\0\2\34\3\0\40\34\1\366\13\34"+
    "\1\367\6\34\22\0\2\34\3\0\6\34\1\370\22\34"+
    "\1\371\31\34\22\0\2\34\3\0\21\34\1\270\41\34"+
    "\22\0\2\34\3\0\1\372\20\34\1\373\41\34\22\0"+
    "\2\34\3\0\10\34\1\374\52\34\22\0\2\34\3\0"+
    "\40\34\1\375\21\34\1\376\22\0\2\34\3\0\52\34"+
    "\1\277\10\34\22\0\2\34\3\0\32\34\1\377\17\34"+
    "\1\u0100\10\34\22\0\2\34\3\0\42\34\1\u0101\20\34"+
    "\22\0\2\34\3\0\27\34\1\270\33\34\22\0\2\34"+
    "\3\0\23\34\1\u0102\37\34\22\0\2\34\3\0\24\34"+
    "\1\264\3\34\1\165\32\34\22\0\2\34\3\0\17\34"+
    "\1\u0103\43\34\22\0\2\34\3\0\60\34\1\277\2\34"+
    "\22\0\2\34\3\0\54\34\1\u0104\6\34\22\0\2\34"+
    "\3\0\55\34\1\271\3\34\1\165\1\34\22\0\2\34"+
    "\3\0\50\34\1\u0105\12\34\22\0\2\34\3\0\10\34"+
    "\1\u0106\11\34\1\u0107\40\34\22\0\2\34\3\0\42\34"+
    "\1\u0108\10\34\1\u0109\7\34\22\0\2\34\3\0\10\34"+
    "\1\u010a\2\34\1\u010b\47\34\22\0\2\34\3\0\42\34"+
    "\1\u010c\1\34\1\u010d\16\34\22\0\2\34\3\0\10\34"+
    "\1\u0102\52\34\22\0\2\34\3\0\23\34\1\u010e\37\34"+
    "\22\0\2\34\3\0\42\34\1\u0104\20\34\22\0\2\34"+
    "\3\0\54\34\1\u010f\6\34\22\0\2\34\3\0\4\34"+
    "\1\u0110\56\34\22\0\2\34\3\0\36\34\1\u0111\24\34"+
    "\22\0\2\34\3\0\4\34\1\223\56\34\22\0\2\34"+
    "\3\0\16\34\1\334\44\34\22\0\2\34\3\0\22\34"+
    "\1\165\40\34\22\0\2\34\3\0\36\34\1\227\24\34"+
    "\22\0\2\34\3\0\47\34\1\334\13\34\22\0\2\34"+
    "\3\0\53\34\1\165\7\34\22\0\2\34\3\0\1\u0112"+
    "\62\34\22\0\2\34\3\0\32\34\1\u0113\30\34\22\0"+
    "\2\34\3\0\4\34\1\165\56\34\22\0\2\34\3\0"+
    "\2\34\1\u010e\60\34\22\0\2\34\3\0\22\34\1\256"+
    "\40\34\22\0\2\34\3\0\22\34\1\u0114\1\165\37\34"+
    "\22\0\2\34\3\0\23\34\1\165\37\34\22\0\2\34"+
    "\3\0\36\34\1\165\24\34\22\0\2\34\3\0\34\34"+
    "\1\u010f\26\34\22\0\2\34\3\0\52\34\1\334\10\34"+
    "\22\0\2\34\3\0\53\34\1\261\7\34\22\0\2\34"+
    "\3\0\32\34\1\155\30\34\22\0\2\34\3\0\53\34"+
    "\1\u0115\1\165\6\34\22\0\2\34\3\0\54\34\1\165"+
    "\6\34\22\0\2\34\3\0\1\u0116\62\34\22\0\2\34"+
    "\3\0\17\34\1\165\43\34\22\0\2\34\3\0\1\34"+
    "\1\u0117\61\34\22\0\2\34\3\0\32\34\1\u0118\30\34"+
    "\22\0\2\34\3\0\50\34\1\165\12\34\22\0\2\34"+
    "\3\0\33\34\1\u0119\27\34\22\0\2\34\3\0\13\34"+
    "\1\165\47\34\22\0\2\34\3\0\14\34\1\165\46\34"+
    "\22\0\2\34\3\0\4\34\1\u011a\56\34\22\0\2\34"+
    "\3\0\4\34\1\u011b\56\34\22\0\2\34\3\0\44\34"+
    "\1\165\16\34\22\0\2\34\3\0\45\34\1\165\15\34"+
    "\22\0\2\34\3\0\36\34\1\u011c\24\34\22\0\2\34"+
    "\3\0\36\34\1\u011d\24\34\22\0\2\34\3\0\22\34"+
    "\1\264\40\34\22\0\2\34\3\0\24\34\1\u011e\36\34"+
    "\22\0\2\34\3\0\1\u011f\62\34\22\0\2\34\3\0"+
    "\53\34\1\271\7\34\22\0\2\34\3\0\55\34\1\u0120"+
    "\5\34\22\0\2\34\3\0\32\34\1\u0121\30\34\22\0"+
    "\2\34\3\0\32\34\1\u0115\30\34\22\0\2\34\3\0"+
    "\1\34\1\u0122\61\34\22\0\2\34\3\0\16\34\1\165"+
    "\44\34\22\0\2\34\3\0\33\34\1\u0123\27\34\22\0"+
    "\2\34\3\0\47\34\1\165\13\34\22\0\2\34\3\0"+
    "\16\34\1\223\44\34\22\0\2\34\3\0\13\34\1\u0124"+
    "\47\34\22\0\2\34\3\0\24\34\1\270\36\34\22\0"+
    "\2\34\3\0\47\34\1\227\13\34\22\0\2\34\3\0"+
    "\44\34\1\u0125\16\34\22\0\2\34\3\0\55\34\1\277"+
    "\5\34\22\0\2\34\3\0\4\34\1\351\56\34\22\0"+
    "\2\34\3\0\1\34\1\u0126\61\34\22\0\2\34\3\0"+
    "\6\34\1\247\54\34\22\0\2\34\3\0\6\34\1\334"+
    "\54\34\22\0\2\34\3\0\36\34\1\353\24\34\22\0"+
    "\2\34\3\0\33\34\1\u0127\27\34\22\0\2\34\3\0"+
    "\40\34\1\251\22\34\22\0\2\34\3\0\40\34\1\334"+
    "\22\34\22\0\2\34\3\0\4\34\1\165\6\34\1\u0128"+
    "\47\34\22\0\2\34\3\0\36\34\1\165\5\34\1\u0129"+
    "\16\34\22\0\2\34\3\0\23\34\1\u012a\37\34\22\0"+
    "\2\34\3\0\15\34\1\u012b\45\34\22\0\2\34\3\0"+
    "\54\34\1\u012a\6\34\22\0\2\34\3\0\46\34\1\u012c"+
    "\14\34\22\0\2\34\3\0\25\34\1\u012d\35\34\22\0"+
    "\2\34\3\0\56\34\1\u012e\4\34\22\0\2\34\3\0"+
    "\6\34\1\264\54\34\22\0\2\34\3\0\10\34\1\u012f"+
    "\52\34\22\0\2\34\3\0\24\34\1\u011b\36\34\22\0"+
    "\2\34\3\0\40\34\1\271\22\34\22\0\2\34\3\0"+
    "\42\34\1\u0130\20\34\22\0\2\34\3\0\55\34\1\u011d"+
    "\5\34\22\0\2\34\3\0\15\34\1\u0131\45\34\22\0"+
    "\2\34\3\0\4\34\1\u0132\56\34\22\0\2\34\3\0"+
    "\23\34\1\u0133\37\34\22\0\2\34\3\0\24\34\1\u0134"+
    "\36\34\22\0\2\34\3\0\23\34\1\265\37\34\22\0"+
    "\2\34\3\0\46\34\1\u0135\14\34\22\0\2\34\3\0"+
    "\36\34\1\u0136\24\34\22\0\2\34\3\0\54\34\1\u0137"+
    "\6\34\22\0\2\34\3\0\55\34\1\u0138\5\34\22\0"+
    "\2\34\3\0\54\34\1\272\6\34\22\0\2\34\3\0"+
    "\13\34\1\264\47\34\22\0\2\34\3\0\4\34\1\u0139"+
    "\56\34\22\0\2\34\3\0\44\34\1\271\16\34\22\0"+
    "\2\34\3\0\36\34\1\u013a\24\34\22\0\2\34\3\0"+
    "\16\34\1\u013b\44\34\22\0\2\34\3\0\10\34\1\u013c"+
    "\52\34\22\0\2\34\3\0\47\34\1\u013d\13\34\22\0"+
    "\2\34\3\0\42\34\1\u013e\20\34\22\0\2\34\3\0"+
    "\3\34\1\334\57\34\22\0\2\34\3\0\1\u013f\62\34"+
    "\22\0\2\34\3\0\35\34\1\334\25\34\22\0\2\34"+
    "\3\0\32\34\1\u0140\30\34\22\0\2\34\3\0\7\34"+
    "\1\165\53\34\22\0\2\34\3\0\41\34\1\165\21\34"+
    "\22\0\2\34\3\0\13\34\1\111\47\34\22\0\2\34"+
    "\3\0\44\34\1\115\16\34\22\0\2\34\3\0\12\34"+
    "\1\165\50\34\22\0\2\34\3\0\43\34\1\165\17\34"+
    "\22\0\2\34\3\0\23\34\1\334\37\34\22\0\2\34"+
    "\3\0\54\34\1\334\6\34\22\0\2\34\3\0\24\34"+
    "\1\u0141\36\34\22\0\2\34\3\0\13\34\1\u0142\47\34"+
    "\22\0\2\34\3\0\55\34\1\u0143\5\34\22\0\2\34"+
    "\3\0\44\34\1\u0144\16\34\22\0\2\34\3\0\17\34"+
    "\1\270\43\34\22\0\2\34\3\0\21\34\1\u013b\41\34"+
    "\22\0\2\34\3\0\50\34\1\277\12\34\22\0\2\34"+
    "\3\0\52\34\1\u013d\10\34\22\0\2\34\3\0\21\34"+
    "\1\264\41\34\22\0\2\34\3\0\13\34\1\u0145\47\34"+
    "\22\0\2\34\3\0\52\34\1\271\10\34\22\0\2\34"+
    "\3\0\44\34\1\u0146\16\34\22\0\2\34\3\0\1\u0147"+
    "\62\34\22\0\2\34\3\0\32\34\1\u0148\30\34\22\0"+
    "\2\34\3\0\24\34\1\u0149\36\34\22\0\2\34\3\0"+
    "\55\34\1\u014a\5\34\22\0\2\34\3\0\3\34\1\u014b"+
    "\57\34\22\0\2\34\3\0\35\34\1\u014c\25\34\22\0"+
    "\2\34\3\0\16\34\1\u014d\44\34\22\0\2\34\3\0"+
    "\47\34\1\u014e\13\34\22\0\1\34\1\165\3\0\63\34"+
    "\22\0\2\34\3\0\23\34\1\u014f\37\34\22\0\2\34"+
    "\3\0\54\34\1\u0150\6\34\22\0\2\34\3\0\4\34"+
    "\1\150\56\34\22\0\2\34\3\0\36\34\1\155\24\34"+
    "\22\0\2\34\3\0\22\34\1\u0151\40\34\22\0\2\34"+
    "\3\0\53\34\1\u0152\7\34\22\0\2\34\3\0\4\34"+
    "\1\u010a\56\34\22\0\2\34\3\0\16\34\1\204\44\34"+
    "\22\0\2\34\3\0\10\34\1\u0153\52\34\22\0\2\34"+
    "\3\0\2\34\1\u0114\60\34\22\0\2\34\3\0\36\34"+
    "\1\u010c\24\34\22\0\2\34\3\0\47\34\1\205\13\34"+
    "\22\0\2\34\3\0\42\34\1\u0154\20\34\22\0\2\34"+
    "\3\0\34\34\1\u0115\26\34\22\0\2\34\3\0\3\34"+
    "\1\u0155\57\34\22\0\2\34\3\0\35\34\1\u0156\25\34"+
    "\22\0\2\34\3\0\15\34\1\165\45\34\22\0\2\34"+
    "\3\0\6\34\1\370\54\34\22\0\2\34\3\0\46\34"+
    "\1\165\14\34\22\0\2\34\3\0\40\34\1\375\22\34"+
    "\22\0\2\34\3\0\23\34\1\246\37\34\22\0\2\34"+
    "\3\0\54\34\1\250\6\34\22\0\2\34\3\0\13\34"+
    "\1\270\47\34\22\0\2\34\3\0\4\34\1\334\56\34"+
    "\22\0\2\34\3\0\44\34\1\277\16\34\22\0\2\34"+
    "\3\0\36\34\1\334\24\34\22\0\2\34\3\0\13\34"+
    "\1\u0157\47\34\22\0\2\34\3\0\44\34\1\u0158\16\34"+
    "\22\0\2\34\3\0\13\34\1\334\47\34\22\0\2\34"+
    "\3\0\44\34\1\334\16\34\22\0\2\34\3\0\3\34"+
    "\1\264\57\34\22\0\2\34\3\0\35\34\1\271\25\34"+
    "\22\0\2\34\3\0\1\165\62\34\22\0\2\34\3\0"+
    "\32\34\1\165\30\34\22\0\2\34\3\0\2\34\1\u0159"+
    "\60\34\22\0\2\34\3\0\34\34\1\u015a\26\34\22\0"+
    "\2\34\3\0\5\34\1\165\5\34\1\u013b\47\34\22\0"+
    "\2\34\3\0\37\34\1\165\4\34\1\u013d\16\34\22\0"+
    "\2\34\3\0\23\34\1\u012d\37\34\22\0\2\34\3\0"+
    "\54\34\1\u012e\6\34\22\0\2\34\3\0\2\34\1\334"+
    "\60\34\22\0\2\34\3\0\34\34\1\334\26\34\22\0"+
    "\2\34\3\0\4\34\1\204\56\34\22\0\2\34\3\0"+
    "\36\34\1\205\24\34\22\0\2\34\3\0\30\34\1\165"+
    "\32\34\22\0\2\34\3\0\61\34\1\165\1\34\22\0"+
    "\2\34\3\0\1\353\62\34\22\0\2\34\3\0\32\34"+
    "\1\353\30\34\1\0";

  private static int [] zzUnpackTrans() {
    int [] result = new int[24272];
    int offset = 0;
    offset = zzUnpackTrans(ZZ_TRANS_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackTrans(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      value--;
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }


  /** Error code for "Unknown internal scanner error". */
  private static final int ZZ_UNKNOWN_ERROR = 0;
  /** Error code for "could not match input". */
  private static final int ZZ_NO_MATCH = 1;
  /** Error code for "pushback value was too large". */
  private static final int ZZ_PUSHBACK_2BIG = 2;

  /**
   * Error messages for {@link #ZZ_UNKNOWN_ERROR}, {@link #ZZ_NO_MATCH}, and
   * {@link #ZZ_PUSHBACK_2BIG} respectively.
   */
  private static final String ZZ_ERROR_MSG[] = {
    "Unknown internal scanner error",
    "Error: could not match input",
    "Error: pushback value was too large"
  };

  /**
   * ZZ_ATTRIBUTE[aState] contains the attributes of state {@code aState}
   */
  private static final int [] ZZ_ATTRIBUTE = zzUnpackAttribute();

  private static final String ZZ_ATTRIBUTE_PACKED_0 =
    "\1\0\1\11\4\1\1\11\3\1\1\11\1\1\1\11"+
    "\61\1\1\11\1\0\2\1\1\11\1\0\2\1\1\0"+
    "\1\11\u0112\1";

  private static int [] zzUnpackAttribute() {
    int [] result = new int[346];
    int offset = 0;
    offset = zzUnpackAttribute(ZZ_ATTRIBUTE_PACKED_0, offset, result);
    return result;
  }

  private static int zzUnpackAttribute(String packed, int offset, int [] result) {
    int i = 0;       /* index in packed string  */
    int j = offset;  /* index in unpacked array */
    int l = packed.length();
    while (i < l) {
      int count = packed.charAt(i++);
      int value = packed.charAt(i++);
      do result[j++] = value; while (--count > 0);
    }
    return j;
  }

  /** Input device. */
  private java.io.Reader zzReader;

  /** Current state of the DFA. */
  private int zzState;

  /** Current lexical state. */
  private int zzLexicalState = YYINITIAL;

  /**
   * This buffer contains the current text to be matched and is the source of the {@link #yytext()}
   * string.
   */
  private char zzBuffer[] = new char[ZZ_BUFFERSIZE];

  /** Text position at the last accepting state. */
  private int zzMarkedPos;

  /** Current text position in the buffer. */
  private int zzCurrentPos;

  /** Marks the beginning of the {@link #yytext()} string in the buffer. */
  private int zzStartRead;

  /** Marks the last character in the buffer, that has been read from input. */
  private int zzEndRead;

  /**
   * Whether the scanner is at the end of file.
   * @see #yyatEOF
   */
  private boolean zzAtEOF;

  /**
   * The number of occupied positions in {@link #zzBuffer} beyond {@link #zzEndRead}.
   *
   * <p>When a lead/high surrogate has been read from the input stream into the final
   * {@link #zzBuffer} position, this will have a value of 1; otherwise, it will have a value of 0.
   */
  private int zzFinalHighSurrogate = 0;

  /** Number of newlines encountered up to the start of the matched text. */
  @SuppressWarnings("unused")
  private int yyline;

  /** Number of characters from the last newline up to the start of the matched text. */
  @SuppressWarnings("unused")
  private int yycolumn;

  /** Number of characters up to the start of the matched text. */
  @SuppressWarnings("unused")
  private long yychar;

  /** Whether the scanner is currently at the beginning of a line. */
  @SuppressWarnings("unused")
  private boolean zzAtBOL = true;

  /** Whether the user-EOF-code has already been executed. */
  @SuppressWarnings("unused")
  private boolean zzEOFDone;

  /* user code: */
    public String lexeme;


  /**
   * Creates a new scanner
   *
   * @param   in  the java.io.Reader to read input from.
   */
  Lexer(java.io.Reader in) {
    this.zzReader = in;
  }

  /**
   * Translates raw input code points to DFA table row
   */
  private static int zzCMap(int input) {
    int offset = input & 255;
    return offset == input ? ZZ_CMAP_BLOCKS[offset] : ZZ_CMAP_BLOCKS[ZZ_CMAP_TOP[input >> 8] | offset];
  }

  /**
   * Refills the input buffer.
   *
   * @return {@code false} iff there was new input.
   * @exception java.io.IOException  if any I/O-Error occurs
   */
  private boolean zzRefill() throws java.io.IOException {

    /* first: make room (if you can) */
    if (zzStartRead > 0) {
      zzEndRead += zzFinalHighSurrogate;
      zzFinalHighSurrogate = 0;
      System.arraycopy(zzBuffer, zzStartRead,
                       zzBuffer, 0,
                       zzEndRead - zzStartRead);

      /* translate stored positions */
      zzEndRead -= zzStartRead;
      zzCurrentPos -= zzStartRead;
      zzMarkedPos -= zzStartRead;
      zzStartRead = 0;
    }

    /* is the buffer big enough? */
    if (zzCurrentPos >= zzBuffer.length - zzFinalHighSurrogate) {
      /* if not: blow it up */
      char newBuffer[] = new char[zzBuffer.length * 2];
      System.arraycopy(zzBuffer, 0, newBuffer, 0, zzBuffer.length);
      zzBuffer = newBuffer;
      zzEndRead += zzFinalHighSurrogate;
      zzFinalHighSurrogate = 0;
    }

    /* fill the buffer with new input */
    int requested = zzBuffer.length - zzEndRead;
    int numRead = zzReader.read(zzBuffer, zzEndRead, requested);

    /* not supposed to occur according to specification of java.io.Reader */
    if (numRead == 0) {
      throw new java.io.IOException(
          "Reader returned 0 characters. See JFlex examples/zero-reader for a workaround.");
    }
    if (numRead > 0) {
      zzEndRead += numRead;
      if (Character.isHighSurrogate(zzBuffer[zzEndRead - 1])) {
        if (numRead == requested) { // We requested too few chars to encode a full Unicode character
          --zzEndRead;
          zzFinalHighSurrogate = 1;
        } else {                    // There is room in the buffer for at least one more char
          int c = zzReader.read();  // Expecting to read a paired low surrogate char
          if (c == -1) {
            return true;
          } else {
            zzBuffer[zzEndRead++] = (char)c;
          }
        }
      }
      /* potentially more input available */
      return false;
    }

    /* numRead < 0 ==> end of stream */
    return true;
  }


  /**
   * Closes the input reader.
   *
   * @throws java.io.IOException if the reader could not be closed.
   */
  public final void yyclose() throws java.io.IOException {
    zzAtEOF = true; // indicate end of file
    zzEndRead = zzStartRead; // invalidate buffer

    if (zzReader != null) {
      zzReader.close();
    }
  }


  /**
   * Resets the scanner to read from a new input stream.
   *
   * <p>Does not close the old reader.
   *
   * <p>All internal variables are reset, the old input stream <b>cannot</b> be reused (internal
   * buffer is discarded and lost). Lexical state is set to {@code ZZ_INITIAL}.
   *
   * <p>Internal scan buffer is resized down to its initial length, if it has grown.
   *
   * @param reader The new input stream.
   */
  public final void yyreset(java.io.Reader reader) {
    zzReader = reader;
    zzEOFDone = false;
    yyResetPosition();
    zzLexicalState = YYINITIAL;
    if (zzBuffer.length > ZZ_BUFFERSIZE) {
      zzBuffer = new char[ZZ_BUFFERSIZE];
    }
  }

  /**
   * Resets the input position.
   */
  private final void yyResetPosition() {
      zzAtBOL  = true;
      zzAtEOF  = false;
      zzCurrentPos = 0;
      zzMarkedPos = 0;
      zzStartRead = 0;
      zzEndRead = 0;
      zzFinalHighSurrogate = 0;
      yyline = 0;
      yycolumn = 0;
      yychar = 0L;
  }


  /**
   * Returns whether the scanner has reached the end of the reader it reads from.
   *
   * @return whether the scanner has reached EOF.
   */
  public final boolean yyatEOF() {
    return zzAtEOF;
  }


  /**
   * Returns the current lexical state.
   *
   * @return the current lexical state.
   */
  public final int yystate() {
    return zzLexicalState;
  }


  /**
   * Enters a new lexical state.
   *
   * @param newState the new lexical state
   */
  public final void yybegin(int newState) {
    zzLexicalState = newState;
  }


  /**
   * Returns the text matched by the current regular expression.
   *
   * @return the matched text.
   */
  public final String yytext() {
    return new String(zzBuffer, zzStartRead, zzMarkedPos-zzStartRead);
  }


  /**
   * Returns the character at the given position from the matched text.
   *
   * <p>It is equivalent to {@code yytext().charAt(pos)}, but faster.
   *
   * @param position the position of the character to fetch. A value from 0 to {@code yylength()-1}.
   *
   * @return the character at {@code position}.
   */
  public final char yycharat(int position) {
    return zzBuffer[zzStartRead + position];
  }


  /**
   * How many characters were matched.
   *
   * @return the length of the matched text region.
   */
  public final int yylength() {
    return zzMarkedPos-zzStartRead;
  }


  /**
   * Reports an error that occurred while scanning.
   *
   * <p>In a well-formed scanner (no or only correct usage of {@code yypushback(int)} and a
   * match-all fallback rule) this method will only be called with things that
   * "Can't Possibly Happen".
   *
   * <p>If this method is called, something is seriously wrong (e.g. a JFlex bug producing a faulty
   * scanner etc.).
   *
   * <p>Usual syntax/scanner level error handling should be done in error fallback rules.
   *
   * @param errorCode the code of the error message to display.
   */
  private static void zzScanError(int errorCode) {
    String message;
    try {
      message = ZZ_ERROR_MSG[errorCode];
    } catch (ArrayIndexOutOfBoundsException e) {
      message = ZZ_ERROR_MSG[ZZ_UNKNOWN_ERROR];
    }

    throw new Error(message);
  }


  /**
   * Pushes the specified amount of characters back into the input stream.
   *
   * <p>They will be read again by then next call of the scanning method.
   *
   * @param number the number of characters to be read again. This number must not be greater than
   *     {@link #yylength()}.
   */
  public void yypushback(int number)  {
    if ( number > yylength() )
      zzScanError(ZZ_PUSHBACK_2BIG);

    zzMarkedPos -= number;
  }




  /**
   * Resumes scanning until the next regular expression is matched, the end of input is encountered
   * or an I/O-Error occurs.
   *
   * @return the next token.
   * @exception java.io.IOException if any I/O-Error occurs.
   */
  public Tokens yylex() throws java.io.IOException {
    int zzInput;
    int zzAction;

    // cached fields:
    int zzCurrentPosL;
    int zzMarkedPosL;
    int zzEndReadL = zzEndRead;
    char[] zzBufferL = zzBuffer;

    int [] zzTransL = ZZ_TRANS;
    int [] zzRowMapL = ZZ_ROWMAP;
    int [] zzAttrL = ZZ_ATTRIBUTE;

    while (true) {
      zzMarkedPosL = zzMarkedPos;

      zzAction = -1;

      zzCurrentPosL = zzCurrentPos = zzStartRead = zzMarkedPosL;

      zzState = ZZ_LEXSTATE[zzLexicalState];

      // set up zzAction for empty match case:
      int zzAttributes = zzAttrL[zzState];
      if ( (zzAttributes & 1) == 1 ) {
        zzAction = zzState;
      }


      zzForAction: {
        while (true) {

          if (zzCurrentPosL < zzEndReadL) {
            zzInput = Character.codePointAt(zzBufferL, zzCurrentPosL, zzEndReadL);
            zzCurrentPosL += Character.charCount(zzInput);
          }
          else if (zzAtEOF) {
            zzInput = YYEOF;
            break zzForAction;
          }
          else {
            // store back cached positions
            zzCurrentPos  = zzCurrentPosL;
            zzMarkedPos   = zzMarkedPosL;
            boolean eof = zzRefill();
            // get translated positions and possibly new buffer
            zzCurrentPosL  = zzCurrentPos;
            zzMarkedPosL   = zzMarkedPos;
            zzBufferL      = zzBuffer;
            zzEndReadL     = zzEndRead;
            if (eof) {
              zzInput = YYEOF;
              break zzForAction;
            }
            else {
              zzInput = Character.codePointAt(zzBufferL, zzCurrentPosL, zzEndReadL);
              zzCurrentPosL += Character.charCount(zzInput);
            }
          }
          int zzNext = zzTransL[ zzRowMapL[zzState] + zzCMap(zzInput) ];
          if (zzNext == -1) break zzForAction;
          zzState = zzNext;

          zzAttributes = zzAttrL[zzState];
          if ( (zzAttributes & 1) == 1 ) {
            zzAction = zzState;
            zzMarkedPosL = zzCurrentPosL;
            if ( (zzAttributes & 8) == 8 ) break zzForAction;
          }

        }
      }

      // store back cached position
      zzMarkedPos = zzMarkedPosL;

      if (zzInput == YYEOF && zzStartRead == zzCurrentPos) {
        zzAtEOF = true;
        return null;
      }
      else {
        switch (zzAction < 0 ? zzAction : ZZ_ACTION[zzAction]) {
          case 1:
            { return ERROR;
            }
            // fall through
          case 16: break;
          case 2:
            { return Espacio;
            }
            // fall through
          case 17: break;
          case 3:
            { return Parrafo;
            }
            // fall through
          case 18: break;
          case 4:
            { return OperadorBooleano;
            }
            // fall through
          case 19: break;
          case 5:
            { return Comentario;
            }
            // fall through
          case 20: break;
          case 6:
            { return OperadorAritmetico;
            }
            // fall through
          case 21: break;
          case 7:
            { return Delimitador;
            }
            // fall through
          case 22: break;
          case 8:
            { return NumeroEntero;
            }
            // fall through
          case 23: break;
          case 9:
            { return Comparador;
            }
            // fall through
          case 24: break;
          case 10:
            { return Asignacion;
            }
            // fall through
          case 25: break;
          case 11:
            { return Variable;
            }
            // fall through
          case 26: break;
          case 12:
            { return Palabras;
            }
            // fall through
          case 27: break;
          case 13:
            { return Numerodecimal;
            }
            // fall through
          case 28: break;
          case 14:
            { return Reservadas;
            }
            // fall through
          case 29: break;
          case 15:
            { return Literal;
            }
            // fall through
          case 30: break;
          default:
            zzScanError(ZZ_NO_MATCH);
        }
      }
    }
  }


}
