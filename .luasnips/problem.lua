local ls = require("luasnip")
local s = ls.snippet
local i = ls.insert_node
local fmt = require("luasnip.extras.fmt").fmt

ls.add_snippets("tex", {
  s("pro", fmt(
    [[
    \begin{{problem}}[{}]
    \end{{problem}}

    \begin{{proof}}[\textit{{ Sol. }}]
      \begin{{equation*}}
        \begin{{aligned}}[t]
          {}
        \end{{aligned}}
        \qquad\qquad
        \begin{{aligned}}[t]
          {}
        \end{{aligned}}
      \end{{equation*}}
    \end{{proof}}
    ]], {
      i(1), i(2), i(3)
    }
  ))
})
