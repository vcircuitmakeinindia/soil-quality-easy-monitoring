export const findP = (l: number, h: number, v: number) => (v - l) / (h - l);
export const findV = (l: number, h: number, p: number) => l + p * (h - l);
export const colorP = (l: number[], h: number[], p: number) => Object.keys(l).map((i) => findV(l[parseInt(i)], h[parseInt(i)], p));
export const rgbaToHex = (rgba: number[]) => "#" + rgba.map(v => Math.round(v).toString(16).padStart(2, "0")).join("");
export const invertRgb = (rgb: number[]) => rgb.map(v => 255 - v);

export default {
    findP,
    findV,
    colorP,
    rgbaToHex,
    invertRgb,
};