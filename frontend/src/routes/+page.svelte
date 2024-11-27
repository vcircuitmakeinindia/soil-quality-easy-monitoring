<script lang="ts">
	import { onMount } from "svelte";
	import Main from "$lib/components/Main.svelte";
  import api from "$lib/api";
	import globals from "$lib/globals";

	let readings = $state([]);

  const update = () => api.getData().then(data => readings = data);

	onMount(() => {
    // fetching data from api
    update();
		const interval = setInterval(update, 10000);
		return () => clearInterval(interval);
	});
</script>

<Main {readings} />
