/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_meanShiftLAB_info.c
 *
 * Code generation for function '_coder_meanShiftLAB_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "meanShiftLAB.h"
#include "_coder_meanShiftLAB_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 4);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString("meanShiftLAB"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(4.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.2.0.538062 (R2017a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[40] = {
    "789ced5d4d6c23c975eef5eeec6e0e9b4c82245e27b16776130cbc9e8548491449791c58fc152989147f254ae3986a368b628bfd4376377fc44bb497c0b9edd1"
    "4002647d08b027c3c71c05c447fbb6de83e3c3de720bf61004f12508c966694889c5e6a89bd5ecd62330e8a97dd3f5aabe7df5d5ab5755af993792a9371886f9",
    "c3c19f6fff3dc394fe69586298f7c6e5c78cfefb0633fdbb2d7f63fc8c4d948772fc7bc4bc352abf774bfecfe332274b1aea697a41e025946e8b15a40c0a122b"
    "a29b6aaab2c84baca4152e9b8851902a0b1d541d496abc800abc880ee48942821f14c4f884e8a630140dff1ea923ae916f8b8c52575f3557982c3013f8fc94d0",
    "ffb716c42740c0e7f1b88ce52f637fe7a9cb22f254149e953c51a43634b9e9890f7a2f3ccd28f205e2348faa701e11b152beced7b48350784dbc69678fd08eb7"
    "176ce79b8476fec1b8fcfe542d1fefe8cf67e3e7e31ddc8e33829e45f17a97d08ec703c9b02c2a55bec3579155fade9e284feb7b7b54aecaed8a805ed9c3e726",
    "f54589faf43296bf4c1e940626d156158f2073ace049850a83ffe39edc86773dc07a3459162a72cf8344c123f0158fc86a025bf1c84dd583115a6b0eeb31c269"
    "51fb987c4edbc7bbb8fcaf474fbf0c51d4c750eedfdf56bef51bdbfa471adf8bdadd9f11f461bbc3f2dec9e969ec3cc42b2d5f478c6d154e42d90b76a21d1903",
    "3d46ed6026cab3fab9ecfa61fcceb3b7af7f6815afbe43c4e99d5179dc49c3fead2a8f4788faf43296dfdf0eb01988a37ae8d9c155e059d63e9e73bb3e5a3c1e"
    "ec666bc592cf1f487484dc7634183c908b1c033c6ef7f86d12dab5a8bd7d63a23ccb4f7fcc4cfeb07ffee18d7f7e6512b72706b86139275791b2c60f1679ca60",
    "05b3c6abe1362f684969b0cc430acfd9c6fbff66525fcea0ff58fe1a7633fcf37c8497e73906cc731bb0b119d19c0722cc7fc03cb0aaf3c09f13f4613bc4f2c3"
    "4e2b12aa253ac142d677c9c54469237e2a24601eb07b1e3823b4cb5a7bfb9e65bcffd400272cbfc5fbea002ad46b4664b1c96afc80899dcafb7983fe63b959de",
    "bf03187dbb09d819e770bb3e5abc5fe99da47335b671944deda7f77248cb7bf387c0fb0f84f7bfbf6395bdfd89014e587e8bf7077d6716eaf7aac67748fb5ab8"
    "df586e96ef07408d2c84a25fef81f88ef3f93d55d4bc27c9e3902415737c46cda6cfd5422be61e7e77cabeeb19a11dd6da9775fbab463c2a36e5ee701bdea9bc",
    "1d26ead3cb586e627f6684900df1981f805fee7cde2ef5fdc59416e35971bbd50dc8d94d8ecb0523eee16da78e5fba71f98d1dfde985b8fc580e71f9bb4fc23c"
    "0071f925ea83b8bc35f53b751e3823b4cb5a7bfb21b5f392bc3ae8b2c2f79ceacfc789faf43296dfcf0e9030f88b076334b4058a76f00fbfff2df0b8d379bca3",
    "712985978be2d6465f6a1c1d6c7753a5441c78fc41f0f855d8321e7f44c4e991be3ed1c3328e8dcb8488faf43296dfdf0ea6cc80a63ffec5cf7f053cbeaa3cbe"
    "e879c993a2f7c29be2931b4af27cef6437b81d8c968e19e071bbc72fddb80c9c9784b8ccbde70188cb2c511fc465aca9ff1784f717c5718f503fc611cb4dcf03",
    "1fd4040d3bbd0c6dbf3e65d9f9996f1ae085e533ce4db24aecdc36de5f413b219e971c026503df7ff4f9ef80ef9dcef7de7437201678f1749fcf5563fb512e5f"
    "ab5d8681ef1fce3866a6f89eb4de5814aff70cf0c2725e957447551b66b6b02fae63d63e9206fdc5f2d7f4076a7c0f559bf2c03c3c5348d910df61b6e1dc8df3",
    "797e77b371996f9df342a41069e45ae1f342a3188b02cf3f549e27e9b36edfb5c60f163575a7c6eb9794e7628ad77584744b003e77873e5af1fa4e0bc59a1d4e"
    "dd2e75376539a3e6d7374f4e19f7f0b953e2aeaff8fc831aafa85a8d9feec719a19d96dadff59965f1faef18e086e50330ca0310ca35591164b959963b48a909",
    "72b7cc0df3cb99f7e76fff48edc13facefda64ff4f0df461f93dcfdbe8663407391be23889af1fb93a6f99adfa68f9f7ea7eac178bf6fb99bdde862fb5e18d64"
    "43eb5e17dd87fa8af0fea2385e11eac73862f9f2c6f507f3ff41b98e842652e8dae9ae65eb81b726cad3f8be75b31e18966dde57e0a52aea2525eda61d9f996c",
    "c78e413bb0dcdc3a614da4681751d8c775fe7c90bf6cf2e2562b77bcce57aabee46936935aefb828def319e1fd073c6e99c9fb544e8fe31bcd275c9d1ded8c43"
    "1cffee93601f10f759a23e88e35b53ff5784f7c1cf3763a7496af913061d17d99e7df3c08ac6fda7ef5b8d30a21ef77f01fcef7cfe177afe53e4bd38f416f9b0",
    "b7d0edafb33e21e3a2f3995f11de07fe3761a75774f99f9780ff8df89f9780ffdda48f16ff6f25538d66238d7a5a22953fcfecee6776bd828bce6bc2beefdd27"
    "d1febe3ab38cd75f377e6f56dfeb9ee7f9cca4be1da23ebd8ce50e8af7419c7e89fa204e6f4dfd66e3b20fe2be15f3ea5ce64f4ce2f5a1015e587e6b5f946d36",
    "85cbfc684e8bb7254ee365691a07b3fb097f64d02e2caf8db597ebac541590657e41d1403f969bf50b66004939bf3103f77097a88fd6bc1013f942c87719ae0a"
    "4db49fda3e6f9e487c18fcfc87389e07ce69ceb2f39d7f69801b96cffe8e4948188038923bf5be56daa0ff586ed1774c4680d1cdab06791896a98f16ff272ba1",
    "e4babfd9e8c48e5ac7de46d8ebcbf27b2ee27f18c7b3db4f3acf63d3ba60b2fb6939a29fed1ffeece27fa7f80d3380a3fd9d13980796a88fd63ca06dec5f965a"
    "e7a5a3fa792390dbd51a7b995ecc45fbbd66c77381503fc611cbcdc787f4887fb926c8ac56be8914d1bde7750479794cea73ff3d6fc8cbb34c7d9097c79afa81",
    "f7ef3e89f67775426d9f576d29da22fd5bd5bc0dcbcdb78d845a5bf20c31b2217f47eaec19f0bad379ddb71babd5bdfee4c5616c33a965b292d489445de4cfc3"
    "f89d676fcf2c8be3ff95014e587e27af725416595e8a298a3c358f354db6c7ecfeae59bffed0403f969bcfb33c0120ddef60be77f225f0bfd3f93f5149e6d26a",
    "6033904bf372a97974d439aa64e0bccf431ac7839fcf327fde380f9bda64151539d59f4f10f5e9652cbf9f3f30c466e8116094689edfbc7a2efd0ff0b9d3f97c"
    "4bc825ba722ab8bb594c9c07b8487f2f97ccbb284e03fefc3c7bfbae65f1f83f35c009cb6ff9f3e8b61f4feaf7aadeb7da35e837969b9def11f579feea932602",
    "7e773abfb77db16269a3bddf53d375359cbac8fbd52d04fcfe40f87dcdb278cd5f18e084e533f75bd77054debebc9a66d775b4ce6b3dd711bbb1199ae76dfeeb"
    "3f81ef5795ef17cdab1c6c1fe4bd479b872125b919934a7b39bf94f333c0f70f8def3f3589d347063861b9f13daca49411580e31d378d81dafbf36a9ff4706fa",
    "b17c09f737c68052cfbff0097cef7c75e78785e3f7dd6824d70bf637653681f6e25a903bac8577dd333f5c13de8771fdb0d609f78df7c33a6176fb619de08c79"
    "00d6097ad9ecf9cc6342fd18472cb72e6f43b93adad02deb2171233f7929df4fbfceede8cfac65fbbb8f88383e1a9579556225c6b9e73523447d7a19cb4de55b",
    "1b62345e5052e479c8cfb3447db478be156a1f8abecb92cf9b5336da9175b4dd11d38c7b781ec6ef3c7bfb1bcbfcfa27063861f99df39ae1362f684929ade78e"
    "77ecbd5b5a79f96e0366c3fd2bb877bb447db4e23c879d5624544b748285acef928b89d246fc5470d1397df0eff5dfaafbf735411e1df001ff9ebc5f34c288be",
    "7f00f7b196a88f16cf075b81c3424b886e35c2f5427637afb5a2512eee1e9e87f13bcfde9e827fcf807f3fd90ff0efedd507febd35f503efcfb337ebe23a26f2"
    "69b2ca1af6ee9d7bae93d67d3dbc5f8b6d8622dffbe1bb29cee7fb4add9f29498256cdcb62ac2d25362bb1f09e8bceed00df2fc6f79f9ac409ce75ced7ff00cf",
    "7fc1b9ce25ea83739dd6d47f4d781fc6f53c3bb4ee5ce7aaac13ee1b1f8275c2ecf6c33ac15df380dbd70966c7f183f81ed7551af23a98d407791dacd2a7ff1e"
    "8a3ec8eb604dfd3f25bcbf288e0142fd18472c7f3918bc7559449e8ac2b392278ad48626373d717e30389f6614f902719a4755388f8858295fe76bda607453cf",
    "b7f66a9f97a4cfaaf33a78ca72ea799d10519f5ec672d3f3fbb81e8abcfdc5cf7f05bcbdaabcbde879fc93a2f7c29be2931b4af27cef6437b81d8c968e19f7f0"
    "b6d973182542fd18472cb7f6bb581fa0569b1554be6f9867d25afb7b61597ce63b06b861f9008cf20084724d5604596e96e50e526a82dc2d73fab7b1ecdac7bd",
    "36d9ff53037d587ecffd1fdd8ce62067c3399ec4d78fbe84f96049fa68f9f1ea7eac178bf6fb99bdde862fb5e18d6443ebde18cc07b8fe07f59ddcab1f5b361f"
    "7cdb00372cbf15b769ab28c32a038a8bc892aa2dd0ff65c56fccc6f93213e559fdc772b376330d18d5fccbbffcf5f7603de074fed72ad528cb05c3d970a42f1e",
    "5e2a8a1735fc2ee27f18c7b3db3f6d779b96c5ebdf37c00bcb49bcefd4739cfb06fab0dc323ba17f0eecff7aff0d7cef74be3f8917bb01bfa26e6ef73bb964ed"
    "249c4771c945e7f6c1dfbffb24dadf4e05e23fe3f2b5c9fe43fc67d9fa68f7cf5e7d10ffb1a67ea7ece33609ed584a1e06e6e31dfd69ddbeee9b449cde1c95d5",
    "f662feeaaaeeeb2ef77e4795d5d851e6eeb6483fcfdacf5015fcfa55e5f145f7755379be5a6a9df66a077df5bcd64b5d24eb528b710f8fc3f89d676f4fed8edf"
    "48ac72ce4b5cbd6197ff6e76dd7764a00fcb17b40fb5ce2aa8ead1577de3b5dfed25e00d6694f327ff4b34f705f0fd92f4d1f2db2f7bdde4361baf9d6f79b9c3",
    "989cbf88b7035d17f9ed6e19cf247b58d4fe487e35f6ebdf67267fd8af7f367e7e48eddc26e4595bd9fbdb90676d89fa20cf9a35f5aff6f8b5dbbfb78ec7df21"
    "e2f4cea83ce8615391ab0fe2dc4de6fe86d054f80eab21cf182eaae76e3e6f40bcc6f17c5e4ff852cdad78752b930f467cfdda691d75b6a2eee17318c7b3db3f",
    "6d775ecbf65f9f18e085e5903f13f267be9e3edafdb3571fe4cfb4a67ee0ffd9ed5fd6b9cb45ed6ed04b0ea96a79dce1322f35db9a6adf39fb6b93faca06fdc6"
    "728bec64367c74ef63ffe38bff05fe773affa3424369b45292af9d9473f2463dc3f50e5417e5c9b926bc0fe37a9e1d6ec03eaec97eafcabe0f0937d8c775863e",
    "d8c7b5a6fe6bc2fb300fccb3c380ddf7705955458a76c40a7c35ca0f431c76c58568ae234ddde798028cea3a12e2414bd4476b1ef0e563fe8dcdbdcea692dadd"
    "8a6f05b24131b309fb010f691c3356f2fe1303bcb01cf603603fe0f5f4d1ee9fbdfa603fc09afa81ff67b77fdaee82705e73417d705ed3327db4fb67ab3e38af",
    "694dfdc0e7b3db3f6d77dfb78ccf8df875d06191edd9b78f6b96cfa3447d7a19cbefcbe783bf78748ca87f07e7057cd7c4f97c2ef4fca7c87b71e82df2616fa1"
    "db5f677d42c645fef935e17d88d3cfb3c3b865fbb5df34c00fcb677edf2a76eed8f8fc12be8743ccb73d04ca86f8cc479fff0ef8dfe9fcef4d77036281174ff7",
    "f95c35b61fe5f2b5daa58bbe7742d39f77ee79cd940d7c2f567809953b88d364a58c04242249530df30639e57bb76706fab1dc22bb21c049d58ed2bb4f216fda"
    "aace078be6dbc92493db87e94cf7249b56785e640f2461b7c9b8673eb826bcefd4714d350fc3ce8f7746cfab97fa73276fd9be2ee4d99caf0ff26c9ad547bb7f",
    "f6ea833c9bd6d4ef943c9b678476aceaf7128df2352855bec357916df19fd5dec71d7e2f718c10fdbc9a81675988fbac2a6f2feae707bbd95ab1e4f307121d21"
    "b71d0d060fe422c7006fbb93b79f59c6db46f990514f8fdc3895b743447d7a19cbcd9cbf196064c3776ee1fccd32f551bb57e53d2ea5f8eee19eff40e6bbc98d",
    "a0af78b9eea2fbb5307ee7d9dbab7c69572671fa96014e583e735f760db3bc7df1965f98ec7fca401f969bdd9f7dae2376633314fdf4c7effe3bf0bdd3f93e59"
    "dbabad270eb4e031bbde3ae2d25eb694a8bbe8fe14f0fd627cffa9499c3e32c009cb6fdf97bdfb39afa49411580eddc203cf074eddaffd91817e2c5fc2f7d1c6",
    "80523fbff9c9ef7f0bf383d3e78744371ac9f582fd4d994da0bdb816e40e6b6117ad07ae09efc3b89e67876bae5b27dc371e04eb84d9ed877582bbe601b7af13"
    "209e3f695f1f5b765ef38f0d70c1f2e1e91151e345a496eb48682265fcdf21fe43da9fbd8318edef20c7207f82f379bd7a7ac9fa2a1c5b8afad8505f8e15c48b",
    "93a68beedb5e13de5f14c79784fa318e586ee938fe8093455196f49373ea547f487190e57cefb6b0337a5c59770ef389019e580ef97520bfceebe9a3dd3f7bf5"
    "417e1d6beabf26bcefd4f3fa54e7879dd39dd1f3ba60f77ddee1a53695efdb779ed3ec7a81d67d5e0c14cc07eed2476b3e68b4f2e950335939e493cd74b1de29",
    "06bd2dcd45f779af09ef433e877976f8e286ff7f6212bfbf36c00fcb6ff13f274baa9696a53c2f9d0b4893253dfbb27dfb022b968f9f381fcc028e723e7e9817"
    "96a88fd6bc10ed1deeef154f7615cdebef5e1c71fcf15ef2c445fb0366fdbbcc4479168e58eeec3c0f3fa0767f8b5751abcd0a8ebd071023ead3cb586e2a6f9b",
    "8e11edfdde28f0b9f3f93c5f6cb5b574f2e8a898cb67fd4a2b94d842ac8bfc7c18bff3ecedd53d5c523c69519c26cbb370c2f251f600bdbf654e569053fdf663"
    "83fe62f93de779dd30f02c7f1b34baebbe5f5fc0f7141dcff36135b78944d40f1f25b64ed96856ca6afeb88be2fb309eef3ec9f6f75dcbe2f8f01dc5d9fae03b",
    "8acee463dafae03b8ae6eaff7f16650618", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 105328U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_meanShiftLAB_info.c) */