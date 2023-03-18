/* global WebAssembly */

// get the list of imports a wasm is looking for
async function getWasmInterface (m) {
  const out = { imports: {}, exports: WebAssembly.Module.exports(m) }
  for (const r of WebAssembly.Module.imports(m)) {
    out.imports[r.module] = out.imports[r.module] || {}
    if (r.kind === 'function') {
      out.imports[r.module][r.name] = () => {}
    }
  }
  return out
}

export default async function (bytes) {
  const m = await WebAssembly.compile(bytes)
  const { imports } = await getWasmInterface(m)
  const { exports } = await WebAssembly.instantiate(m, imports)
  return {
    tts (text) {
      exports.main()
    }
  }
}
